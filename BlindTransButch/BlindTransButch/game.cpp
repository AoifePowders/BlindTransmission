
#include "Game.h"
#include <iostream>

Game::Game() :

	m_window{ sf::VideoMode{ unsigned(screenSize::s_width), unsigned(screenSize::s_height), 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	m_player.setUp();
	m_controller.connect();
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
	world.initialise(1);



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

	if (m_exitGame)
	{
		m_window.close();
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
	world.render(m_window);
	m_player.render(m_window);
	m_cat.render(m_window);
	m_enemy.render(m_window);
	m_vase.render(m_window);
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
				switch (currentLevel)
				{
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