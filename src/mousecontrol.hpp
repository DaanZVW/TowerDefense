#ifndef MOUSE_CONTROL_HPP
#define MOUSE_CONTROL_HPP

// Include std::Libs
#include <iostream>

// Include external files
#include "button.hpp"
#include "menu.hpp"
#include "tilemap.hpp"
#include "tower.hpp"

/// @brief Class for tracking the mouse position and clicks.
class mouseControl{
private:
	tilemap & map;
	menu & menuSide;
	tower *newTower;
	towerGroup & towers;

	bool placeTower = false;
	bool availableSpot = false;

public:

	/// @brief Construct a mouseControl by nessesary information
	/// 
	/// @param tilemap 	    an Tilemap for access the tilemap
	/// @param menu			an Menu for acces the menu
	/// @param towerGroup	Group of towers for adding, removing, upgrading or selecting an tower.
	///
	mouseControl( tilemap & map, menu & menuSide, towerGroup & towers);

	/// @brief	Drag new towers or get menuTower info.
	///
	/// @param	mousePointer	The mouse Position.
	/// @return void
	///
	void updateMouse( const sf::Vector2i & mousePointer );

	/// @brief  For adding, removing, upgrading or selecting towers.
	///
	/// @param	mousePointer	The mouse position.
	/// @return void
	///
	void selectClick( const sf::Vector2i & mousePointer );
	
	/// @brief deselect the selected tower.
	///
	/// @return void
	///
	void deselectClick();
};


#endif /*MOUSE_CONTROL_HPP*/