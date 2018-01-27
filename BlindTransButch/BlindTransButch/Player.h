#ifndef PLAYER
#define PLAYER
#include<SFML\Graphics.hpp>

class Player
{
public:
	Player();
	~Player();

	void setUp();
	void render(sf::RenderWindow & t_window);
	
	sf::RectangleShape m_player;
	sf::Vector2f m_size{ 20.0f,20.0f };
};
#endif // !PLAYER
