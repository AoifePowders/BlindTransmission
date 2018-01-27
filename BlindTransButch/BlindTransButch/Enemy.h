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

	bool m_isMoving;

private:
	sf::RectangleShape m_body;
	sf::Texture m_knucklesTexture;
};

#endif // !ENEMY
