#include "Win.h"



Win::Win()
{
}


Win::~Win()
{
}

void Win::setUp(sf::Font &t_font, sf::Texture &t_texture)
{
	m_winText.setCharacterSize(80);
	m_winText.setFillColor(sf::Color(117,3,3,150));
	m_winText.setFont(t_font);
	m_winText.setPosition(100, 100);
	m_winText.setString("So you think you've escaped?\nWell you're wrong!\nMuahahaha");

	m_winRect.setPosition(800, 350);
	m_winRect.setSize(sf::Vector2f{ 350, 350 });
	m_winRect.setTexture(&t_texture);
	m_winRect.setFillColor(sf::Color(255, 255, 255, 100));

}

void Win::update()
{
	counter++;
	if (counter == 500)
	{
		m_switchStart = true;
	}
}

void Win::render(sf::RenderWindow &t_window)
{
	t_window.draw(m_winText);
	t_window.draw(m_winRect);
}
