#ifndef PLAYER
#define PLAYER
#include<SFML\Graphics.hpp>
#include "Xbox360Controller.h"
#include "screenSize.h"

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

	void setUp();
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
};
#endif // !PLAYER
