#include "SoundEmitter.h"


double distance(sf::Vector2f v1, sf::Vector2f v2);

SoundEmitter::SoundEmitter()
{
}
SoundEmitter::~SoundEmitter()
{
}
SoundEmitter::SoundEmitter(sf::Vector2f p, std::shared_ptr<Audio> a, int t, sf::Color c)
{
	m_ttl = t;
	m_pos = p;
	m_circle.setOrigin(p);
	m_circle.setPosition(p);
	m_radius = 0;
	m_circle.setRadius(0);
	m_circle.setFillColor(sf::Color::Transparent);
	m_circle.setOutlineThickness(5);
	m_circle.setOutlineColor(c);
	alive = true;
	//a->playSingle();
}
bool SoundEmitter::checkCollision(sf::IntRect r)
{
	
	sf::Vector2f rCentre(r.left + r.width / 2, r.top + r.height / 2);
	if (m_radius >= distance(m_circle.getPosition(), rCentre))
	{
		std::cout << "helllllllllllllp " << std::endl;
		return true;
	}
}
void SoundEmitter::update()
{
	if (m_ttl > 0)
	{
		m_radius += 20;
		m_circle.setRadius(m_radius);
		m_circle.setOrigin(sf::Vector2f(m_radius, m_radius));
		m_ttl--;
	}
	else
	{
		alive = false;
	}
}
void SoundEmitter::render(sf::RenderWindow &w)
{
	w.draw(m_circle);
}

double distance(sf::Vector2f v1, sf::Vector2f v2)
{
	return sqrt(((v2.x - v1.x) * (v2.x - v1.x)) + ((v2.y - v1.y) * (v2.y - v1.y)));
}