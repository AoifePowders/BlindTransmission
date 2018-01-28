#ifndef CAT
#define CAT

#include <SFML\Graphics.hpp>
#include "SoundEmitter.h"
#include <iostream>
#include <chrono>
#include <thread>


class Cat
{
public:
	Cat();
	~Cat();

	void update();
	void render(sf::RenderWindow & w);
	void meow();
	void setup(sf::Vector2f pos, const std::string & file, Audio & s);
	sf::IntRect getRect();
	sf::Vector2f m_position{ 200,200 };

	bool contact;
	bool catAlive{ true };

private:
	sf::Texture m_catTexture;
	sf::Sprite m_sprite;
	sf::IntRect m_rect;
	std::vector<SoundEmitter*> m_mews;
	Audio m_sound;

};
#endif // !CAT
