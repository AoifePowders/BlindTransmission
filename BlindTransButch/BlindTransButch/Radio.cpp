#include "Radio.h"



Radio::Radio()
{
	m_radioTexture.loadFromFile("ASSETS\\IMAGES\\Radio.png");
	m_body.setTexture(&m_radioTexture);
}


Radio::~Radio()
{
}

void Radio::setup(sf::Vector2f t_pos)
{
	m_body.setPosition(t_pos);
}

void Radio::update()
{
}

void Radio::render(sf::RenderWindow &t_window)
{
	t_window.draw(m_body);
}
