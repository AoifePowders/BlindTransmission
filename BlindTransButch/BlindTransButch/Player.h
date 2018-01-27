#ifndef PLAYER
#define PLAYER
#include<SFML\Graphics.hpp>
#include "screenSize.h"

class Player
{
public:
	Player();
	~Player();

	void setUp();
	void move();
	void boundary();
	void render(sf::RenderWindow & t_window);
	
	sf::RectangleShape m_player;
	sf::Vector2f m_size{ 50.0f,50.0f };
	sf::Vector2f m_position{ 500.f, 500.0f };
};
#endif // !PLAYER
