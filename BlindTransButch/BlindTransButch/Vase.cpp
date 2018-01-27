#include "Vase.h"

Vase::Vase()
{
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
}

void Vase::render(sf::RenderWindow & t_window)
{
}
