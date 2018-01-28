#include "MainMenu.h"



MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

void MainMenu::setUp(sf::Font & t_font, sf::Texture &t_texture)
{
	sf::String Text[] = { "Start", "Exit" };
	for (int i = 0; i < m_buttonNumber; i++)
	{
		m_button[i].setFillColor(sf::Color(92, 6, 6, 255));
		m_button[i].setPosition(1000,(i * 100) + 510);
		m_button[i].setSize(sf::Vector2f{ 200,50 });
		m_button[i].setOrigin(25, 25);

		m_buttonText[i].setFont(t_font);
		m_buttonText[i].setString(Text[i]);
		m_buttonText[i].setFillColor(sf::Color::White);
		m_buttonText[i].setCharacterSize(45);
		m_buttonText[i].setPosition(990 , (i * 100) + 475);
	}

	m_background.setSize(sf::Vector2f(464, 464));
	m_background.setPosition(150, 100);
	m_background.setTexture(&t_texture);
	m_background.setFillColor(sf::Color(255, 255, 255, 25));
}

void MainMenu::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_background);
	for (int i = 0; i < m_buttonNumber; i++)
	{
		t_window.draw(m_button[i]);
		t_window.draw(m_buttonText[i]);
	}
}

void MainMenu::keyIsPressed(Xbox360Controller & t_controller)
{
	if (t_controller.m_currentState.DpadUp)
	{
		m_currentButton -= 1;
	}

	if (t_controller.m_currentState.DpadDown)
	{
		m_currentButton += 1;
	}

	if (m_currentButton == 0)
	{
		m_button[0].setFillColor(sf::Color(11,6,92,255));
		m_button[0].setOutlineColor(sf::Color::White);
		m_button[0].setOutlineThickness(5);

		m_button[1].setFillColor(sf::Color(92, 6, 6, 255));
		m_button[1].setOutlineThickness(0);
		m_lastButton = 0;
		if (t_controller.m_currentState.A)
		{
			m_keyPressedStart = true;
		}
	}

	if (m_currentButton == 1)
	{
		m_button[0].setFillColor(sf::Color(92, 6, 6, 255));
		m_button[0].setOutlineThickness(0);

		m_button[1].setOutlineColor(sf::Color::White);
		m_button[1].setOutlineThickness(5);
		m_button[1].setFillColor(sf::Color(11, 6, 92, 255));
		m_lastButton = 1;
		if (t_controller.m_currentState.A)
		{
			m_keyPressedExit = true;
		}
	}

	if (m_currentButton > 1 || m_currentButton < 0)
	{
		m_currentButton = m_lastButton;
	}
}

void MainMenu::update(sf::Time & t_dtime)
{
	if (m_keyPressedStart == true)
	{
		m_switchStart = true;
	}

	if (m_keyPressedExit == true)
	{
		m_switchExit = true;
	}
	m_keyPressedExit = false;
}
