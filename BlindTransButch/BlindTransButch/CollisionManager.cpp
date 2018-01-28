//Created by Dale Sinnott, Connor Maguire
#include "CollisionManager.h"
#include <iostream>

CollisionManager::CollisionManager()
{

}

bool CollisionManager::checkCollision(sf::Vector2f &point, sf::FloatRect &box)
{
	if (box.contains(point))
	{
		return true;
	}
	return false;
}

bool CollisionManager::checkCollision(sf::Vector2f &point, sf::IntRect &box)
{
	sf::Vector2i intVect;
	intVect.x = point.x;
	intVect.y = point.y;
	if (box.contains(intVect))
	{
		return true;
	}
	return false;

}
bool CollisionManager::checkCollision(sf::IntRect &a, sf::IntRect &b)
{
	if (a.intersects(b))
	{
		return true;
	}
	return false;
}
bool CollisionManager::checkCollision(sf::RectangleShape & a, sf::RectangleShape & b)
{
	if (b.getGlobalBounds().intersects(a.getGlobalBounds()))
	{
		return true;
	}
	return false;
}
bool CollisionManager::checkCollision(sf::RectangleShape &a, sf::IntRect &b)
{
	sf::IntRect iA(a.getGlobalBounds());
	if (iA.intersects(b))
	{
		return true;
	}
	return false;
}
bool CollisionManager::checkCollision(sf::RectangleShape &a, sf::FloatRect &b)
{
	sf::IntRect iA(a.getGlobalBounds());
	if (iA.intersects(asIntRect(b)))
	{
		return true;
	}
	return false;
}
float CollisionManager::getHorizontalIntersectionDepth(sf::FloatRect &a, sf::FloatRect &b)
{
	float halfWidthA = a.width / 2;
	float halfWidthB = b.width / 2;

	float centerA = a.left + halfWidthA;
	float centerB = b.left + halfWidthB;

	float distanceX = centerA - centerB;
	float minDistanceX = halfWidthA + halfWidthB;

	if (std::abs(distanceX) >= minDistanceX)
	{
		return 0;
	}

	if (distanceX > 0) {
		return minDistanceX - distanceX;
	}
	else
	{
		return -minDistanceX - distanceX;
	}
}
float CollisionManager::getVerticalIntersectionDepth(sf::FloatRect &a, sf::FloatRect &b)
{
	float halfHeightA = a.height / 2;
	float HalfHeightB = b.height / 2;

	float centerA = a.top + halfHeightA;
	float centerB = b.top + HalfHeightB;

	float distanceY = centerA - centerB;
	float minDistanceY = halfHeightA + HalfHeightB;

	if (std::abs(distanceY) >= minDistanceY)
	{
		return 0;
	}

	if (distanceY > 0) {
		return minDistanceY - distanceY;
	}
	else
	{
		return -minDistanceY - distanceY;
	}
}
sf::FloatRect CollisionManager::asFloatRect(sf::IntRect &rect)
{
	return sf::FloatRect(rect.left, rect.top, rect.width, rect.height);
}
sf::IntRect CollisionManager::asIntRect(sf::FloatRect &rect)
{
	return sf::IntRect(rect.left, rect.top, rect.width, rect.height);
}
sf::FloatRect CollisionManager::asFloatRect(sf::RectangleShape &rect)
{
	sf::IntRect r(rect.getGlobalBounds());
	return sf::FloatRect(r.left, r.top, r.width, r.height);
}