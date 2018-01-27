#ifndef CAT
#define CAT

#include <SFML\Graphics.hpp>
#include <iostream>

class Cat
{
public:
	Cat();
	~Cat();

	void update();
	void render(sf::RenderWindow & t_window);

	sf::Vector2f m_position{ 200,200 };

	bool m_meowing;
private:
	sf::RectangleShape m_body;
	sf::Texture m_catTexture;

};
#endif // !CAT
