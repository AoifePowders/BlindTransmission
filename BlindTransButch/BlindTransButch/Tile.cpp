//Created by Dale Sinnott, Connor Maguire
#include "Tile.h"
#include <iostream>
Tile::Tile(sf::Vector2f position,
	std::shared_ptr<sf::Texture> _floorTexture,
	std::shared_ptr<sf::Texture> _wallTexture,
	std::shared_ptr<sf::Texture> _exitTexture,
	std::shared_ptr<sf::Texture> _tableTexture,
	std::shared_ptr<sf::Texture> _chairTexture,
	std::shared_ptr<sf::Texture> _bedTexture,
	std::shared_ptr<sf::Texture> _entranceTexture,
	int const size = 86) :
	m_position(position), m_size(size, size)
{
	floorTexture = _floorTexture;
	wallTexture  = _wallTexture;
	exitTexture = _exitTexture;
	chairTexture = _chairTexture;
	tableTexture = _tableTexture;
	bedTexture = _bedTexture;
	entranceTexture = _entranceTexture;
	
	m_TileSprite.setTexture(*floorTexture);
	//m_TileSprite.setOrigin(floorTexture->getSize().x / 2, floorTexture->getSize().y / 2);
	m_TileSprite.setPosition(position.x, position.y);
	bounds.top = position.y;
	bounds.left = position.x;
	bounds.width = size;
	bounds.height = size;
	tileType = Tile::DEFAULT;
}
Tile::~Tile()
{

}
void Tile::update()
{
	
}
void Tile::setType(Tile::TileType newType)
{
	bounds.width = 86;
	bounds.height = 86;
	switch (newType)
	{
	case Tile::ENTRANCE:
		m_TileSprite.setTexture(*entranceTexture);
		break;
	case Tile::BED:
		m_TileSprite.setTexture(*bedTexture);
		break;
	case Tile::TABLE:
		m_TileSprite.setTexture(*tableTexture);
		break;
	case Tile::CHAIR:
		m_TileSprite.setTexture(*chairTexture);
		break;
	case Tile::EXIT:
		m_TileSprite.setTexture(*exitTexture);
		break;
	case Tile::WALL:
		m_TileSprite.setTexture(*wallTexture);
		break;
	case Tile::DEFAULT:
		m_TileSprite.setTexture(*floorTexture);
		break;
	default:
		break;
	}
	tileType = newType;
}
void Tile::render(sf::RenderWindow &window)
{
	window.draw(m_TileSprite);
}
void Tile::updatePosition(sf::Vector2f newPos)
{
	m_TileSprite.setPosition(newPos.x, newPos.y);
	bounds.top = newPos.y;
	bounds.left = newPos.x;
}