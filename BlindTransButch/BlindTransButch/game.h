#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Audio.h"
#include "SoundEmitter.h"
#include <memory>

#include "Player.h"
#include "Enemy.h"
#include "Cat.h"

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

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	Audio musik;

	Enemy m_enemy;
	Cat m_cat;
};

#endif // !GAME

