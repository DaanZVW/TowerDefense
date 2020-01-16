#ifndef MOUSE_CONTROL_HPP
#define MOUSE_CONTROL_HPP

#include "menu.hpp"
#include "tilemap.hpp"
#include "tower.hpp"

class mouseControl{
private:
	tilemap & map;
	menu & menuSide;
	bool placeTower = false;
	tower *newTower;
	towerGroup & towers;


public:
	mouseControl( tilemap & map, menu & menuSide, towerGroup & towers);

	void updateMouse( const sf::Vector2i & mousePointer );

	void mouseClick( const sf::Vector2i & mousePointer );

};


#endif /*MOUSE_CONTROL_HPP*/