#include "mousecontrol.hpp"

mouseControl::mouseControl( tilemap & map, menu & menuSide, towerGroup & towers):
	map( map ),
	menuSide( menuSide ),
	towers( towers )
{}

void mouseControl::updateMouse( const sf::Vector2i & mousePointer ){
	if (placeTower == true ){
		if ( map.getTilePosition(sf::Vector2i{mousePointer}) == sf::Vector2i{-1,-1} ){
			newTower->setPosition(sf::Vector2f{float(mousePointer.x), float(mousePointer.y)});
		} else {
			sf::Vector2i tilePosition = map.getTilePosition( mousePointer );
			auto tile = map.getTileFromIndex( tilePosition );
			sf::Color color = newTower->getFillColor();

			newTower->setPosition( tile->getPosition() );
			newTower->setSize( tile->getSize() );

			if ( tile->getAllowPlacement() ){
				newTower->setFillColor( newTower->mycolor );
				availableSpot = true;
			} else {
				newTower->setFillColor( sf::Color::Red );
				availableSpot = false;
			}
		}
	}
}

void mouseControl::selectClick( const sf::Vector2i & mousePointer ){
	sf::Vector2i tilePosition = map.getTilePosition( mousePointer );
	auto tile = map.getTileFromIndex( tilePosition );
	
	// Check if mouse is pointing at something outside the tilemap
	if ( map.getTilePosition(sf::Vector2i{mousePointer}) == sf::Vector2i{-1,-1} ) {
		for ( auto &menuTower : menuSide.getTowers() ){
			if (menuTower->getGlobalBounds().contains( sf::Vector2f{ float(mousePointer.x), float(mousePointer.y) } )){
				if ( towers.towers.size() >= 1 ) {
					for ( auto &tower : towers.towers ) {
						tower->selected = false;
					}
				}

				// Deselect if tower is selected
				if (placeTower) {
					deselectClick();
				}

				// Make new tower which is the same as clicked
				placeTower = true;
				newTower = new tower{ 
					menuTower->name,
					menuTower->damage,
					menuTower->range,
					menuTower->firerate,
					menuTower->getFillColor()
				};
				newTower->setSize(menuTower->getSize());

				// Add newtower to the towers vector
				towers.add(newTower);
			}
		}
		
	// When the tile is empty and a tower is held, place the tile
	} else if ( placeTower && availableSpot ){
		placeTower = false;
		towers.addTmpTower();
		towers.showTmpTower = false;

		// sf::Vector2i tilePosition = map.getTilePosition( mousePointer );
		// auto tile = map.getTileFromIndex( tilePosition );

		tile->setAllowPlacement( false );
		if ( towers.isTower( tile ) ) {
			tower* selectedTower = towers.getTower( tile );
			selectedTower->selected = false;
		}

	// When the tile selected is a tower
	} else if ( !placeTower && map.getTilePosition(sf::Vector2i{ mousePointer }) != sf::Vector2i{-1,-1} ) {
		// sf::Vector2i tilePosition = map.getTilePosition( mousePointer );
		// auto tile = map.getTileFromIndex( tilePosition );

		if ( towers.towers.size() >= 1 ) {
			for ( auto &tower : towers.towers ) {
				tower->selected = false;
			}
		}

		if ( towers.isTower( tile ) ) {
			tower* selectedTower = towers.getTower( tile );
			if ( selectedTower->selected ) {
				selectedTower->selected = false;
			}else {
				selectedTower->selected = true;
			}

			for ( auto &tower : towers.towers ) {
				if ( tower != selectedTower ) {
					tower->selected = false;
				}
			}
		}
	}
}

void mouseControl::deselectClick() {
	placeTower = false;
	towers.clearTmpTower();
}