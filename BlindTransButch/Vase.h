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
	sf::RectangleShape m_body;

private:
	
	sf::Texture m_vaseSolidTexture;
	sf::Texture m_vaseBrokenTexture;
};

#endif // !VASE



