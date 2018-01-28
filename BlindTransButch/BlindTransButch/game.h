#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Audio.h"

#include "Player.h"
#include "Enemy.h"
#include "Xbox360Controller.h"
#include "Cat.h"
#include "screenSize.h"
#include "Grid.h"
#include "CollisionManager.h"
#include "MainMenu.h"

enum class GameState
{
	MAINMENU,
	PLAYING,
	WIN,
	LOSE
};

class Game
{
public:
	Game();
	~Game();
	void run();

	static GameState m_currentState;

private:
	Player m_player;
	Xbox360Controller m_controller;
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void setupFontAndText();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Texture m_knucklesTexture;
	bool m_exitGame; // control exiting game
	Audio musik;

	Enemy m_enemy;
	Cat m_cat;
	MainMenu m_mainMenuScreen;
	Grid world;

	int currentLevel = 1;
	CollisionManager cManager;
	void checkCollision();


};

#endif // !GAME

