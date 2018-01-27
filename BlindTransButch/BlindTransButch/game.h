#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"
#include "Cat.h"
#include "screenSize.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	Player m_player;
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();

	sf::RenderWindow m_window; 
	sf::Font m_ArialBlackfont; 
	bool m_exitGame; 

	Enemy m_enemy;
	Cat m_cat;

};

#endif // !GAME

