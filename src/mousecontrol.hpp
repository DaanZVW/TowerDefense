#ifndef MOUSE_CONTROL_HPP
#define MOUSE_CONTROL_HPP

#include "menu.hpp"
#include "tilemap.hpp"
#include "tower.hpp"

class mouseControl{
private:
	tilemap & map;
	menu & menuSide;
	tower *newTower;
	tower *selectedTower;
	towerGroup & towers;

	bool placeTower = false;
	bool availableSpot = false;

public:
	mouseControl( tilemap & map, menu & menuSide, towerGroup & towers);

	void updateMouse( const sf::Vector2i & mousePointer );

	void selectClick( const sf::Vector2i & mousePointer );
	void deselectClick();
};


#endif /*MOUSE_CONTROL_HPP*/