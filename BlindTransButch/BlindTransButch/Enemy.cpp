#include "Enemy.h"

Enemy::Enemy()
{
	if (!m_knucklesTexture.loadFromFile("ASSETS\\IMAGES\\Knuckles.png"))
	{
		std::cout << "Knuckles not loaded" << std::endl;
	}

	m_body.setSize(sf::Vector2f(64, 64));
	m_body.setTexture(&m_knucklesTexture);
	m_body.setFillColor(sf::Color(255, 255, 255, 150));
}


Enemy::~Enemy()
{
}

void Enemy::update()
{
	move();
	m_body.setPosition(m_position);
}

void Enemy::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
}

void Enemy::move()
{
	sf::Vector2f direction;
	direction.x = m_target.x - m_position.x;
	direction.y = m_target.y- m_position.y;

	float hypot = sqrt(direction.x * direction.x + direction.y * direction.y);
	direction.x /= hypot;
	direction.y /= hypot;

	m_position.x += direction.x * speed;
	m_position.y += direction.y * speed;
}


