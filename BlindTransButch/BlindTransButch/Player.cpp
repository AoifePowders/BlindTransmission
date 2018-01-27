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

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_position.y--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_position.x--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_position.y++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_position.x++;
	}
	m_player.setPosition(m_position);
}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_player);
}
