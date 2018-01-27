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

void Player::move(Xbox360Controller &t_controller)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		m_speed = 10;
	}
	else
	{
		m_speed = 5;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || t_controller.m_currentState.DpadRight == true)
	{
		m_position.x += m_speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || t_controller.m_currentState.DpadLeft == true)
	{
		m_position.x -= m_speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || t_controller.m_currentState.DpadUp == true)
	{
		m_position.y -= m_speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || t_controller.m_currentState.DpadDown == true)
	{
		m_position.y += m_speed;
	}
	m_player.setPosition(m_position);
}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_player);
}
