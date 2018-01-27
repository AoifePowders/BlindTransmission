#ifndef ENEMY
#define ENEMY

#include <SFML\Graphics.hpp>

class Enemy
{
public:
	Enemy();
	~Enemy();

	void update();
	void render(sf::RenderWindow t_window);

private:

};

#endif // !ENEMY
