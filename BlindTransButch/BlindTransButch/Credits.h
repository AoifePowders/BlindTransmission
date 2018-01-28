#ifndef CREDITS_
#define CREDITS_

#include <SFML\Graphics.hpp>
#include "Xbox360Controller.h"

class Credits
{
public:
	Credits();
	~Credits();

	void setUp(sf::Font &t_font);
	void update();
	void render(sf::RenderWindow &t_window);
	bool m_switchStart = false;

private:
	sf::Text m_creditsText;
	int m_positionY = 700;
	int counter = 0;

};

#endif //!CREDITS_

