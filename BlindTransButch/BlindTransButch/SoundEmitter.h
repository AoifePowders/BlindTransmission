#pragma once
#include<SFML\Graphics.hpp>
#include "Audio.h"
#include <vector>
#include <memory>
#include <math.h>

class SoundEmitter
{
public:
	SoundEmitter();
	~SoundEmitter();

	SoundEmitter(sf::Vector2f p, std::shared_ptr<Audio> a, int t, sf::Color c);

	bool checkCollision(sf::IntRect r);
	void update();
	void render(sf::RenderWindow &w);
	bool alive;

private:
	Audio m_sfx;
	sf::CircleShape m_circle;
	float m_radius;
	int m_ttl;
	sf::Vector2f m_pos;
};

