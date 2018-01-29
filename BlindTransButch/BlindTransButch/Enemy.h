#ifndef ENEMY
#define ENEMY

#include <SFML\Graphics.hpp>
#include <iostream>

class Enemy
{
public:
	Enemy();
	~Enemy();

	void update();
	void render(sf::RenderWindow & t_window);

	float speed{ .5f };

	void move();

	bool m_isMoving{ false };

	sf::Vector2f m_target{ 250, 101 };
	sf::Vector2f m_position{ 100, 100 };

	sf::RectangleShape m_body;

	
private:
	sf::Texture m_knucklesTexture;

	
};

#endif // !ENEMY
