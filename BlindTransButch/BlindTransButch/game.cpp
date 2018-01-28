
#include "Game.h"
#include <iostream>

GameState Game::m_currentState = GameState::CREDITS;

Game::Game() :

	m_window{ sf::VideoMode{ unsigned(screenSize::s_width), unsigned(screenSize::s_height), 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	loadSounds();
	setupFontAndText(); // load font 
	for (int i = 0; i < 5; i++)
	{
		playerSounds.push_back(a);
	}
	m_player.setUp(playerSounds);
	m_controller.connect();
	m_mainMenuScreen.setUp(m_ArialBlackfont, m_knucklesTexture);
	m_winScreen.setUp(m_ArialBlackfont, m_knucklesTexture);
	m_loseScreen.setUp(m_ArialBlackfont, m_knucklesTexture);
	m_creditsScreen.setUp(m_ArialBlackfont);
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps


	//Initialise
	loadLevel(1);
         
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
			m_player.update(timePerFrame, m_controller);
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
	if (m_controller.isConnected())
	{
		if (m_controller.m_currentState.Back)
		{
			m_window.close();
		}
	}

	switch (m_currentState)
	{
	case GameState::MAINMENU:
		m_mainMenuScreen.keyIsPressed(m_controller);
		break;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_controller.isConnected())
	{
		m_controller.update();
	}
	else
	{
		m_controller.connect();
	}
	m_controller.m_previousState = m_controller.m_currentState;
	
	switch (m_currentState)
	{
	case GameState::MAINMENU:
		m_mainMenuScreen.update(t_deltaTime);
		m_mainMenuScreen.keyIsPressed(m_controller);
		if (m_mainMenuScreen.m_switchStart || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			m_currentState = GameState::PLAYING;
			m_mainMenuScreen.m_switchStart = false;
		}
		if (m_mainMenuScreen.m_switchExit == true)
		{
			m_window.close();
		}
		break;
	case GameState::PLAYING:
		world.update();
		m_player.move(m_controller);
		checkCollision();
		break;
	case GameState::WIN:
		if (m_winScreen.m_switchStart == true)
		{
			m_currentState = GameState::PLAYING;
		}
		m_winScreen.update();
		break;
	case GameState::LOSE:
		if (m_loseScreen.m_switchStart == true)
		{
			m_currentState = GameState::PLAYING;
		}
		m_loseScreen.update();
		break;
	case GameState::CREDITS:
		if (m_creditsScreen.m_switchStart == true)
		{
			m_currentState = GameState::WIN;
		}
		m_creditsScreen.update();
		break;
	}

	for (int i = 0; i < 5; i++)
	{
		if (m_cats[i].catAlive)
		{
			m_cats[i].update();
		}
	}

	world.update();

	m_vase.update();

	m_player.move(m_controller);
	checkCollision();

}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	switch (m_currentState)
	{
	case GameState::MAINMENU:
		m_mainMenuScreen.render(m_window);
		break;
	case GameState::PLAYING:
		world.render(m_window);
		m_vase.render(m_window);
		for (int i = 0; i < 5; i++)
		{
			m_cats[i].render(m_window);
		}
		m_player.render(m_window);
		m_enemy.render(m_window);
		break;
	case GameState::WIN:
		m_winScreen.render(m_window);
		break;
	case GameState::LOSE:
		m_loseScreen.render(m_window);
		break;
	case GameState::CREDITS:
		m_creditsScreen.render(m_window);
		break;
	}
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{ 
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}

	if (!m_knucklesTexture.loadFromFile("ASSETS\\IMAGES\\Knuckles.png"))
	{
		std::cout << "Knuckles not loaded" << std::endl;
	}
}

void Game::checkCollision()
{

	if (cManager.checkCollision(m_player.m_body, m_vase.m_body))
	{
		m_vase.isBroken = true;
	}

	for (int i = 0; i < world.map.size(); i++)
	{
		if (cManager.checkCollision(m_player.m_position, world.map.at(i)->bounds))
		{
			if (world.map.at(i)->tileType == Tile::EXIT)
			{
				//EXIT, LOAD NEXT LEVEL
				currentLevel++;
				loadLevel(currentLevel);
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (cManager.checkCollision(m_player.m_body, m_cats[i].getRect()))
			{
				if (cManager.checkCollision(m_player.m_body, m_cats[i].getRect()))
				{
					m_cats[i].catAlive = false;
				}
			}
		}

		if (cManager.checkCollision(m_player.m_body, world.map.at(i)->bounds) && world.map.at(i)->tileType != Tile::DEFAULT && world.map.at(i)->tileType != Tile::EXIT)
		{
			float offsetX = cManager.getHorizontalIntersectionDepth(cManager.asFloatRect(m_player.m_body), cManager.asFloatRect(world.map.at(i)->bounds));
			float offsetY = cManager.getVerticalIntersectionDepth(cManager.asFloatRect(m_player.m_body), cManager.asFloatRect(world.map.at(i)->bounds));

			if (std::abs(offsetX) > std::abs(offsetY))
			{
				m_player.m_position.y += offsetY;
			}
			else
			{
				m_player.m_position.x += offsetX;
			}
		}
		
	}
}
void Game::loadLevel(int levelnum)
{
	switch (currentLevel)
	{
	case 1:
		m_player.m_position = sf::Vector2f(86 * 2, 86 * 6);
		world.initialise(1);
		break;
	case 2:
		m_player.m_position = sf::Vector2f(86 * 2, 86 * 6);
		world.initialise(2);
		break;
	case 3:
		m_player.m_position = sf::Vector2f(86 * 2, 86 * 6);
		world.initialise(3);
		break;
	case 4:
		m_player.m_position = sf::Vector2f(86 * 2, 86 * 6);
		world.initialise(4);
		break;
	case 5:
		m_player.m_position = sf::Vector2f(86 * 2, 86 * 6);
		world.initialise(5);
		break;
	default:
		break;
	}
}
void Game::loadSounds()
{
	playerSounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//playerLow.wav", 50, "lowScan")));
	playerSounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//playerHigh.wav", 50, "highScan")));
	playerSounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//callcatLow.wav", 50, "lowCat")));
	playerSounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//callcatHigh.wav", 50, "highCat")));
	playerSounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//playerBreathe.wav", 50, "breathe")));
	playerSounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//playerBreathe.wav", 50, "lowStep")));
	playerSounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//playerBreathe.wav", 50, "highStep")));	//

	catMeows.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//meow1.wav", 50, "Tina")));
	catMeows.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//meow2.wav", 50, "Fred")));
	catMeows.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//meow3.wav", 50, "Kaplan")));
	catMeows.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//meow4.wav", 50, "Harold")));
	catMeows.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//meow5.wav", 50, "Geoffrey")));

	enemySounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//shadowClick.wav", 50, "click")));
	enemySounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//shadowClose.wav", 50, "close")));
	enemySounds.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//shadowAttack.wav", 50, "attack")));

	soundEffects.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//door.wav", 50, "door")));
	soundEffects.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//bump.wav", 50, "bump")));
	soundEffects.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//RadioStatic.wav", 50, "staticRadio")));
	soundEffects.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//radiovoice.wav", 50, "voiceRadio")));
	soundEffects.push_back(std::make_shared<Audio>(Audio("ASSETS//SOUNDS//vaseBreak.wav", 50, "vaseBreak")));
}