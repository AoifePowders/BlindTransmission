//Created by Dale Sinnott, Connor Maguire

#ifndef _TILE_H_
#define _TILE_H_

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML\Graphics.hpp>
#include <memory>

class Tile {
public:

	Tile(sf::Vector2f position,
		std::shared_ptr<sf::Texture> _floorTexture, 
		std::shared_ptr<sf::Texture> _wallTexture,
		std::shared_ptr<sf::Texture> _exitTexture,
		std::shared_ptr<sf::Texture> _tableTexture,
		std::shared_ptr<sf::Texture> _chairTexture,
		std::shared_ptr<sf::Texture> _bedTexture,
		std::shared_ptr<sf::Texture> _entranceTexture,
		int const size);
	~Tile();

	void update();
	void render(sf::RenderWindow &window);
	void updatePosition(sf::Vector2f newPos);
	sf::IntRect bounds;
	sf::RectangleShape m_rect;
	sf::Sprite m_TileSprite;
	std::shared_ptr<sf::Texture> floorTexture;
	std::shared_ptr<sf::Texture> wallTexture;
	std::shared_ptr<sf::Texture> exitTexture;
	std::shared_ptr<sf::Texture> chairTexture;
	std::shared_ptr<sf::Texture> tableTexture;
	std::shared_ptr<sf::Texture> bedTexture;
	std::shared_ptr<sf::Texture> entranceTexture;
	enum TileType 
	{ 
		ENTRANCE,
		RADIO,
		BED, 
		TABLE,
		CHAIR,
		EXIT,
		WALL,
		DEFAULT //floor
	}; 

	void setType(Tile::TileType newType);
	TileType tileType;
private:
	sf::Vector2f m_position;
	sf::Vector2i m_size;
	int count = 0;

};
#endif;
