#ifndef VASE
#define VASE

#include <iostream>
#include <SFML\Graphics.hpp>

class Vase
{
public:
	Vase();
	~Vase();

	
	void update();
	void render(sf::RenderWindow & t_window);

	bool isBroken{ false };

private:
	sf::RectangleShape m_body;
	sf::Texture m_vaseSolidTexture;
	sf::Texture m_vaseBrokenTexture;
};

#endif // !VASE



