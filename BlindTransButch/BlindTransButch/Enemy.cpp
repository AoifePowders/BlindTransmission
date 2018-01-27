#include "Enemy.h"

Enemy::Enemy()
{
	if (!m_knucklesTexture.loadFromFile("ASSETS\\IMAGES\\Knuckles.png"))
	{
		std::cout << "Knuckles not loaded" << std::endl;
	}

	m_body.setSize(sf::Vector2f(150, 189));
	m_body.setTexture(&m_knucklesTexture);
	m_body.setFillColor(sf::Color(255, 255, 255, 150));
}


Enemy::~Enemy()
{
}

void Enemy::update()
{
}

void Enemy::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
}

