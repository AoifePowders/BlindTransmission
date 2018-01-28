#include "Lose.h"



Lose::Lose()
{
}


Lose::~Lose()
{
}

void Lose::setUp(sf::Font & t_font, sf::Texture & t_texture)
{
	m_loseText.setCharacterSize(80);
	m_loseText.setFillColor(sf::Color(117, 3, 3, 150));
	m_loseText.setFont(t_font);
	m_loseText.setPosition(100, 100);
	m_loseText.setString("YOU LOSE\n Mwahahaha ");

	m_loseRect.setPosition(800, 350);
	m_loseRect.setSize(sf::Vector2f{ 350, 350 });
	m_loseRect.setTexture(&t_texture);
	m_loseRect.setFillColor(sf::Color(255, 255, 255, 100));
}

void Lose::update()
{
	counter++;
	if (counter == 500)
	{
		m_switchStart = true;
	}
}

void Lose::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_loseText);
	t_window.draw(m_loseRect);
}
