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
	m_player.setPosition(10.0f, 10.0f);
	m_player.setSize(m_size);
}

void Player::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_player);
}
