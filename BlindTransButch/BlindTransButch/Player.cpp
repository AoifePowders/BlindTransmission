#include "Player.h"
#include <iostream>

Player::Player()
{
	if (!m_walk1Texture.loadFromFile("ASSETS\\IMAGES\\PlayerWalk1.png"))
	{
		std::cout << "walking1 not loaded" << std::endl;
	}
	if (!m_walk2Texture.loadFromFile("ASSETS\\IMAGES\\PlayerWalk2.png"))
	{
		std::cout << "walking2 not loaded" << std::endl;
	}
	if (!m_idleTexture.loadFromFile("ASSETS\\IMAGES\\Player.png"))
	{
		std::cout << "Idle not loaded" << std::endl;
	}
}

Player::~Player()
{
}

void Player::setUp(std::vector<std::shared_ptr<Audio>> s)
{
	m_body.setFillColor(sf::Color::White);
	m_body.setPosition(m_position);
	m_body.setSize(m_size);
	m_sounds = s;
	m_breathTimer = 0;
	outOfBreath = false;
	breathSound = true;
	m_body.setOrigin(m_body.getSize().x * .5, m_body.getSize().y * .5);
}

void Player::update(sf::Time t_deltaTime, Xbox360Controller &t_controller, Enemy & enemy)
{
	//Sound emitters
	m_breathTimer--;
	playerCalls(t_controller, enemy);
	for (int i = 0; i < m_calls.size(); i++)
	{
		if (m_calls.at(i)->alive)
		{
			m_calls.at(i)->update();
		}
		else
		{
			delete m_calls.at(i);
			m_calls.erase(m_calls.begin() + i);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || t_controller.m_currentState.RB)
	{
		if (m_breath > 0 && !outOfBreath)
		{
			m_speed = 1.5;
			m_breath -= 0.3;
			m_currentAnimation = PlayerAnimation::Running;
			if (m_breath <= 0)
			{
				m_breath = 0;
				m_speed = .5f;
				outOfBreath = true;
				if (breathSound)
				{	
					//m_sounds.at(4)->playSingle();
					std::cout << "breath goddamnit" << std::endl;
					breathSound = false;
				}
				
			}
		}
	}
	else
	{
		
		m_speed = .5f;
		m_breath += 0.5;
		if (m_breath >= 30)
		{
			m_breath = 30;
			outOfBreath = false;	
			breathSound = true;
		}
	}

	/*if (m_breath <= 0)
	{
		m_speed = 1;	
	}*/

	switch (m_currentAnimation)
	{
	case Walking:
		if (frame <= 14)
		{
			m_body.setTexture(&m_walk1Texture);
		}
		else if (frame > 14)
		{
			m_body.setTexture(&m_walk2Texture);
		}
		frame++;
		if (frame >= 28)
		{
			frame = 0;
		}

		break;
	case Running:
		if (frame <= 7)
		{
			m_body.setTexture(&m_walk1Texture);
		}
		else if (frame > 7)
		{
			m_body.setTexture(&m_walk2Texture);
		}
		frame++;
		if (frame >= 14)
		{
			frame = 0;
		}

		break;
	case Idle:
		m_body.setTexture(&m_idleTexture);
		break;
	default:
		break;
	}

}

void Player::move(Xbox360Controller &t_controller)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || t_controller.m_currentState.DpadRight)
	{
		m_position.x += m_speed;
		m_body.setOrigin(m_body.getSize().x * .5, m_body.getSize().y * .5);
		m_body.setRotation(270);
		m_currentAnimation = PlayerAnimation::Walking;
		}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || t_controller.m_currentState.DpadLeft)
	{
		m_position.x -= m_speed;
		m_body.setOrigin(m_body.getSize().x * .5, m_body.getSize().y * .5);
		m_body.setRotation(90);
		m_currentAnimation = PlayerAnimation::Walking;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || t_controller.m_currentState.DpadUp)
	{
		m_position.y -= m_speed;
		m_body.setOrigin(m_body.getSize().x * .5, m_body.getSize().y * .5);
		m_body.setRotation(180);
		m_currentAnimation = PlayerAnimation::Walking;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || t_controller.m_currentState.DpadDown)
	{
		m_position.y += m_speed;
		m_body.setOrigin(m_body.getSize().x * .5, m_body.getSize().y * .5);
		m_body.setRotation(0);
		m_currentAnimation = PlayerAnimation::Walking;
	}
	else
	{
		m_currentAnimation = PlayerAnimation::Idle;
	}
	m_body.setPosition(m_position);
	
}

void Player::render(sf::RenderWindow & t_window)
{
	for (int i = 0; i < m_calls.size(); i++)
	{
		m_calls.at(i)->render(t_window);
	}
	t_window.draw(m_body);
}
bool Player::checkSoundCollision(sf::IntRect &a)
{
	for (int i = 0; i < m_calls.size(); i++)
	{
		if (m_calls.at(i)->alive)
		{
			if (m_calls.at(i)->checkCollision(a))
			{
				return true;
			}
		}
	}
	return false;
}

void Player::playerCalls(Xbox360Controller &t_controller, Enemy & enemy)
{

	if (m_breathTimer < 0)
	{
		//Low scan
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || t_controller.m_currentState.B)
		{
			enemy.m_target = m_position;
			m_calls.push_back(new SoundEmitter(sf::Vector2f(m_position.x, m_position.y), m_sounds.at(0), 10, sf::Color::White));
			m_breathTimer = 100;
		}
		//high Scan
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || t_controller.m_currentState.A)
		{
			enemy.m_target = m_position;
			m_calls.push_back(new SoundEmitter(sf::Vector2f(m_position.x, m_position.y), m_sounds.at(1), 15, sf::Color::Magenta));
			m_breathTimer = 200;
		}
		//Low Cat
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || t_controller.m_currentState.X)
		{
			enemy.m_target = m_position;
			m_calls.push_back(new SoundEmitter(sf::Vector2f(m_position.x, m_position.y), m_sounds.at(2), 10, sf::Color::Green));
			m_breathTimer = 100;
		}
		//High cat
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || t_controller.m_currentState.Y)
		{
			enemy.m_target = m_position;
			m_calls.push_back(new SoundEmitter(sf::Vector2f(m_position.x, m_position.y), m_sounds.at(3), 15, sf::Color::Cyan));
			m_breathTimer = 200;
		}
	}
}
