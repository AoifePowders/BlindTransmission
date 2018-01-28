#ifndef PLAYER
#define PLAYER
#include<SFML\Graphics.hpp>
#include "Xbox360Controller.h"
#include "screenSize.h"
#include <memory>
#include <vector>
#include "SoundEmitter.h"
#include "Enemy.h"

enum PlayerAnimation
{
	Walking,
	Running,
	Idle
};

class Player
{
public:
	Player();
	~Player();

	void setUp(std::vector<std::shared_ptr<Audio>> s);
	void move(Xbox360Controller &t_controller);
	void render(sf::RenderWindow & t_window);
	void update(sf::Time t_deltaTime, Xbox360Controller &t_controller, Enemy & enemy);
	
	sf::RectangleShape m_body;
	sf::Vector2f m_size{ 64.0f,64.0f };
	sf::Vector2f m_position{ 500.f, 500.0f };
	float m_speed;
	float m_breath = 200;


	int frame{ 0 };
		
	sf::Texture m_idleTexture;
	sf::Texture m_walk1Texture;
	sf::Texture m_walk2Texture;
	
	PlayerAnimation m_currentAnimation{ PlayerAnimation::Idle };
	bool checkSoundCollision(sf::IntRect &a);

private:

	std::vector<SoundEmitter*> m_calls;

	//order of sound:
	// 0. Low Scan
	// 1. High Scan
	// 2. Low Cat
	// 3. High cat
	// 4. panting
	std::vector<std::shared_ptr<Audio>> m_sounds;
	void playerCalls(Xbox360Controller &t_controller, Enemy & enemy);

	int m_breathTimer;
	bool outOfBreath;
	bool breathSound;
};
#endif // !PLAYER
