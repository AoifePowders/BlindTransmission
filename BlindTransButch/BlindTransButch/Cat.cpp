#include "Cat.h"



Cat::Cat()
{
	m_body.setSize(sf::Vector2f(50, 50));
	m_body.setFillColor(sf::Color::Yellow);
}


Cat::~Cat()
{
}

void Cat::update()
{
}

void Cat::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_body);
}
