#ifndef TOWER_HPP
#define TOWER_HPP

#include "tilemap.hpp"

class tower : public sf::RectangleShape{
private:

	tilemap & map;

public:

	tower( tilemap & map ):
	map( map )
	{}

	void placeTower( const sf::Vector2i & mousePosition );

};





#endif /*TOWER_HPP*/