#ifndef PLAYER
#define PLAYER
#include<SFML\Graphics.hpp>
#include "Xbox360Controller.h"
#include "screenSize.h"
#include <memory>
#include <vector>
#include "SoundEmitter.h"

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
	void update(sf::Time t_deltaTime, Xbox360Controller &t_controller);
	
	sf::RectangleShape m_body;
	sf::Vector2f m_size{ 64.0f,64.0f };
	sf::Vector2f m_position{ 500.f, 500.0f };
	float m_speed;
	int m_breath = 200;

	int frame{ 0 };
		
	sf::Texture m_idleTexture;
	sf::Texture m_walk1Texture;
	sf::Texture m_walk2Texture;
	
	PlayerAnimation m_currentAnimation{ PlayerAnimation::Idle };

private:

	std::vector<SoundEmitter*> m_calls;
	std::vector<std::shared_ptr<Audio>> m_sounds;
	void playerCalls(Xbox360Controller &t_controller);

	int breathTimer;
};
#endif // !PLAYER
