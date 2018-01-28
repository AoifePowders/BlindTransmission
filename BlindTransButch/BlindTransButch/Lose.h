#ifndef LOSE_
#define LOSE_

#include <SFML\Graphics.hpp>
#include "Xbox360Controller.h"
class Lose
{
public:
	Lose();
	~Lose();
	void setUp(sf::Font &t_font, sf::Texture &t_texture);
	void update();
	void render(sf::RenderWindow &t_window);
	bool m_switchStart = false;

private:
	sf::Text m_loseText;
	sf::RectangleShape m_loseRect;
	int counter = 0;

};

#endif //!LOSE_