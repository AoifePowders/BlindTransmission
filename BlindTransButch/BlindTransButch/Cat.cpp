#include "Cat.h"



Cat::Cat()
{
}
Cat::~Cat()
{
}
void Cat::setup(sf::Vector2f pos, const std::string & file, std::shared_ptr<Audio> s)
{
	m_catTexture.loadFromFile(file);
	m_sprite.setTexture(m_catTexture);
	m_sprite.setPosition(pos);
	m_rect.left = pos.x;
	m_rect.top = pos.y;
	m_rect.width = m_sprite.getGlobalBounds().width;
	m_rect.height = m_sprite.getGlobalBounds().height;
	m_sound = s;
}
void Cat::update()
{
	if (contact)
	{
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		meow();
		contact = false;
	}
	for (int i = 0; i < m_mews.size(); i++)
	{
		if (m_mews.at(i)->alive)
		{
			m_mews.at(i)->update();
		}
		else
		{
			delete m_mews.at(i);
			m_mews.erase(m_mews.begin() + i);
		}
	}
	if (catAlive == false)
	{
		m_position = sf::Vector2f(-200, -200);
		
	}
	m_sprite.setPosition(m_position);

}	
void Cat::render(sf::RenderWindow & w)
{
	for (int i = 0; i < m_mews.size(); i++)
	{
		m_mews.at(i)->render(w);

	}
	if (catAlive)
	{
		w.draw(m_sprite);
	}
}
void Cat::meow()
{
	m_mews.push_back(new SoundEmitter(sf::Vector2f(m_sprite.getPosition().x + (m_sprite.getGlobalBounds().width / 2), m_sprite.getPosition().y + (m_sprite.getGlobalBounds().height / 2)), m_sound, 10, sf::Color::Yellow));
}
sf::IntRect Cat::getRect()
{
	return m_rect;
}