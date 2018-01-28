#include "Credits.h"



Credits::Credits()
{
}


Credits::~Credits()
{
}

void Credits::setUp(sf::Font & t_font)
{
	m_creditsText.setCharacterSize(80);
	m_creditsText.setFillColor(sf::Color(117, 3, 3, 150));
	m_creditsText.setFont(t_font);
	m_creditsText.setPosition(500, m_positionY);
	m_creditsText.setString("PROGRAMMING:\nDale Sinnot\nConnor Maguire\nEoin Abbey-Maher\nAoife Powders\nART:\nStephen Lynch\nSOUND:\nDale Sinnot");
}

void Credits::update()
{
	counter++;
	if (counter < 1000)
	{
		m_positionY-=2;
		m_creditsText.setPosition(500, m_positionY);
	}
	if (counter == 900)
	{
		m_switchStart = true;
	}
}

void Credits::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_creditsText);
}
