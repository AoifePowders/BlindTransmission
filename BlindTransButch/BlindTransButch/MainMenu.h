#ifndef MAINMENU_
#define MAINMENU_
#include <SFML\Graphics.hpp>
#include "Xbox360Controller.h"

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void setUp(sf::Font &t_font, sf::Texture &t_texture);
	void render(sf::RenderWindow &t_window);
	void keyIsPressed(Xbox360Controller &t_controller);
	void update(sf::Time &t_dtime);

	bool m_switchStart;
	bool m_switchExit;

private:
	static const int m_buttonNumber = 2;
	sf::RectangleShape m_button[m_buttonNumber];
	sf::Text m_buttonText[m_buttonNumber];
	sf::RectangleShape m_background;

	bool m_moved = false;
	int m_currentButton = 0;
	bool m_lastButton = 0;
	
	bool m_keyPressedStart;
	bool m_keyPressedExit;

};

#endif // !MAINMENU_