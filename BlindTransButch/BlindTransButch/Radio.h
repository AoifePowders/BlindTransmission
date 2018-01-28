#ifndef RADIO
#define RADIO

#include <iostream>
#include "SFML\Graphics.hpp"

class Radio
{
public:
	Radio();
	~Radio();

	void setup(sf::Vector2f t_pos);
	void update();
	void render(sf::RenderWindow & t_window);

	sf::RectangleShape m_body;
	sf::Texture m_radioTexture;

private:

};

#endif // !RADIO
