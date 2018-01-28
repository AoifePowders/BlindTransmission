#ifndef WIN_
#define WIN_

#include <SFML\Graphics.hpp>
#include "Xbox360Controller.h"

class Win
{
public:
	Win();
	~Win();

	void setUp(sf::Font &t_font, sf::Texture &t_texture);
	void update();
	void render(sf::RenderWindow &t_window);
	bool m_switchStart = false;
private:
	sf::Text m_winText;
	sf::RectangleShape m_winRect;
	int counter = 0;
};

#endif //!WIN_