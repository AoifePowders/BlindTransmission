#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"

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
	void setupSprite();

	sf::RenderWindow m_window; 
	sf::Font m_ArialBlackfont; 
	sf::Text m_welcomeMessage; 
	sf::Texture m_logoTexture;
	sf::Sprite m_logoSprite; 
	bool m_exitGame; 

	Enemy m_enemy;

};

#endif // !GAME

