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

void Player::setUp()
{
	m_body.setFillColor(sf::Color::White);
	m_body.setPosition(m_position);
	m_body.setSize(m_size);
	m_body.setOrigin(m_body.getSize().x * .5, m_body.getSize().y * .5);
}

void Player::update(sf::Time t_deltaTime, Xbox360Controller &t_controller)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || t_controller.m_currentState.RB)
	{
		m_speed = 1.5;
		m_breath -= 0.3;
		m_currentAnimation = PlayerAnimation::Running;
	}
	else
	{
		m_speed = .5f;
		m_breath += 0.3;
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
	t_window.draw(m_body);
}

