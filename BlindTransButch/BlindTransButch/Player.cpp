#include "Player.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::setUp()
{
	m_player.setFillColor(sf::Color::White);
	m_player.setPosition(m_position);
	m_player.setSize(m_size);
}

void Player::update(sf::Time t_deltaTime, Xbox360Controller &t_controller)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || t_controller.m_currentState.RB)
	{
		m_speed = 10;
		m_breath -= 0.3;
	}
	else
	{
		m_speed = 5;
		m_breath += 0.3;
	}

	/*if (m_breath <= 0)
	{
		m_speed = 1;	
	}*/

}

void Player::move(Xbox360Controller &t_controller)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || t_controller.m_currentState.DpadRight)
	{
		m_position.x += m_speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || t_controller.m_currentState.DpadLeft)
	{
		m_position.x -= m_speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || t_controller.m_currentState.DpadUp)
	{
		m_position.y -= m_speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || t_controller.m_currentState.DpadDown)
	{
		m_position.y += m_speed;
	}
	m_player.setPosition(m_position);
}

void Player::boundary()
{
	if (m_position.x == 0)
	{
		m_player.setPosition(m_position.x + 1, m_position.y);
	}
	if (m_position.y == 0)
	{
		m_player.setPosition(m_position.x, m_position.y + 1);
	}
	if (m_position.x == screenSize::s_width)
	{
		m_player.setPosition(m_position.x - 1, m_position.y);
	}
	if (m_position.y == screenSize::s_height)
	{
		m_player.setPosition(m_position.x, m_position.y - 1);
	}
}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_player);
}

