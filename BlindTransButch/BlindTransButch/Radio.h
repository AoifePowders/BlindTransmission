#ifndef RADIO
#define RADIO

#include <iostream>
#include "SFML\Graphics.hpp"

class Radio
{
public:
	Radio();
	~Radio();

	void update();
	void render(sf::RenderWindow & t_window);

	sf::RectangleShape m_body;
};

#endif // !RADIO
