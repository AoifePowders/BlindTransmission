#ifndef PLAYER
#define PLAYER
#include<SFML\Graphics.hpp>
#include "Xbox360Controller.h"
#include "screenSize.h"


class Player
{
public:
	Player();
	~Player();

	void setUp();
	void move(Xbox360Controller &t_controller);
	void render(sf::RenderWindow & t_window);
	
	sf::RectangleShape m_player;
	sf::Vector2f m_size{ 64.0f,64.0f };
	sf::Vector2f m_position{ 500.f, 500.0f };
	float m_speed;
};
#endif // !PLAYER
