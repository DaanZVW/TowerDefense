#ifndef MOUSE_CONTROL_HPP
#define MOUSE_CONTROL_HPP

// Include std::Libs
#include <iostream>

// Include external files
#include "button.hpp"
#include "menu.hpp"
#include "tilemap.hpp"
#include "tower.hpp"

// Defines for money multipliers
#define GIVE_BACK_MULTIPLIER	0.80
#define PAY_MULTIPLIER			1.25

// Defines for upgrade stats
#define DAMAGE_ADDITION			2
#define RANGE_ADDITION			1

class mouseControl{
private:
	tilemap & map;
	menu & menuSide;
	tower *newTower;
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