#ifndef ENEMY
#define ENEMY

#include <SFML\Graphics.hpp>
#include <iostream>

class Enemy
{
public:
	Enemy();
	~Enemy();

	void update(sf::Vector2f t_soundPos);
	void render(sf::RenderWindow & t_window);

	bool m_isMoving{ false };
	sf::Vector2f m_position{ 200,200 };
	sf::RectangleShape m_body;
	
private:
	sf::Texture m_knucklesTexture;

	void move(sf::Vector2f t_soundPos);
};

#endif // !ENEMY
