#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Audio.h"
#include "SoundEmitter.h"
#include <memory>

#include "Player.h"
#include "Enemy.h"
#include "Xbox360Controller.h"
#include "Cat.h"
#include "screenSize.h"
#include "Grid.h"
#include "CollisionManager.h"
#include "Vase.h"
#include "MainMenu.h"

#include "Radio.h"
#include "Win.h"
#include "Lose.h"
#include "Credits.h"

enum class GameState
{
	MAINMENU,
	PLAYING,
	WIN,
	LOSE,
	CREDITS
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
	Vase m_vase;
	
	std::vector<Cat> m_cats;
	
	Radio m_radio;

	Credits m_creditsScreen;
	MainMenu m_mainMenuScreen;
	Grid world;
	Win m_winScreen;
	Lose m_loseScreen;

	int currentLevel = 1;
	CollisionManager cManager;
	void checkCollision();
	void loadLevel(int levelnum);
	void loadSounds();
	void darken();
	std::vector<std::shared_ptr<Audio>> soundEffects;
	std::vector<std::shared_ptr<Audio>> catMeows;
	std::vector<std::shared_ptr<Audio>> enemySounds;
	std::vector<std::shared_ptr<Audio>> playerSounds;
	std::shared_ptr<Audio> a;
	bool doorLocked = true;

};

#endif // !GAME

