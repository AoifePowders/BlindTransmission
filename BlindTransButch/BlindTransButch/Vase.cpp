#include "Vase.h"
#include <iostream>

Vase::Vase()
{
	if (!m_vaseSolidTexture.loadFromFile("ASSETS\\IMAGES\\Vase.png"))
	{
		std::cout << "solid vase not loaded" << std::endl;
	}

	if (!m_vaseBrokenTexture.loadFromFile("Assets\\IMAGES\\VaseBroken.png"))
	{
		std::cout << "broken Vase not loaded" << std::endl;
	}

	m_body.setTexture(&m_vaseSolidTexture);
	m_body.setSize(sf::Vector2f(86, 86));

	m_body.setPosition(110, 100);
}


Vase::~Vase()
{
}

void Vase::update()
{
	if (isBroken)
	{
		m_body.setTexture(&m_vaseBrokenTexture);
	}
	else
	{
		m_body.setTexture(&m_vaseSolidTexture);
	}
	
}

void Vase::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
}
