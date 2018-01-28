////////////////////////////////////////////////////////////
//
// Created by Dale Sinnott, Connor Maguire
//
////////////////////////////////////////////////////////////
#ifndef _CollisionManager_H_
#define _CollisionManager_H_
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML\Graphics.hpp>
#include <memory>
class CollisionManager
{
public:
	CollisionManager();
	bool checkCollision(sf::Vector2f &point, sf::FloatRect &box);
	bool checkCollision(sf::Vector2f &point, sf::IntRect &box);
	bool checkCollision(sf::RectangleShape &point, sf::IntRect &box);
	bool checkCollision(sf::IntRect &a, sf::IntRect &b);
	bool checkCollision(sf::RectangleShape &a, sf::RectangleShape &b);
	bool checkCollision(sf::RectangleShape &a, sf::FloatRect &b);
	float getHorizontalIntersectionDepth(sf::FloatRect &a, sf::FloatRect &b);
	float getVerticalIntersectionDepth(sf::FloatRect &a, sf::FloatRect &b);
	sf::FloatRect asFloatRect(sf::IntRect& rect);
	sf::IntRect asIntRect(sf::FloatRect &rect);
	sf::FloatRect asFloatRect(sf::RectangleShape &rect);
private:

};
#endif;