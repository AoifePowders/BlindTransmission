#include "Enemy.h"

Enemy::Enemy()
{
	if (!m_knucklesTexture.loadFromFile("ASSETS\\IMAGES\\Knuckles.png"))
	{
		std::cout << "Knuckles not loaded" << std::endl;
	}

	m_body.setSize(sf::Vector2f(150, 150));
	m_body.setTexture(&m_knucklesTexture);
	
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

