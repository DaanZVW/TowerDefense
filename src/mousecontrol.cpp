#include "mousecontrol.hpp"

mouseControl::mouseControl( tilemap & map, menu & menuSide, towerGroup & towers
):
	map( map ),
	menuSide( menuSide ),
	towers( towers )
{}

void mouseControl::updateMouse( const sf::Vector2i & mousePointer ){
	// Track the mouse and place it at the mousepointer
	if (placeTower ){
		if ( map.getTilePosition(sf::Vector2i{mousePointer}) == sf::Vector2i{-1,-1} ){
			newTower->setPosition(sf::Vector2f{
				float(mousePointer.x - map.getTileSize()/2), 
				float(mousePointer.y - map.getTileSize()/2)
			});
			newTower->setFillColor( newTower->mycolor );
			newTower->setFillColor( newTower->mycolor );
			availableSpot = true;

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

	} else {
		if ( map.getTilePosition(sf::Vector2i{mousePointer}) == sf::Vector2i{-1,-1} ){
			// Check if the mouse is looking at an tower
			for ( auto &menuTower : menuSide.getTowers() ){
				if (menuTower->getGlobalBounds().contains( sf::Vector2f{ float(mousePointer.x), float(mousePointer.y) } )){
					// Stop further action if the player has insufficient money
					if ( menuTower->value > menuSide.getMoney() ) {
						menuSide.insufficientMoney = true;
					} else {
						menuSide.insufficientMoney = false;
					}

					std::vector<std::string> textInTextObjects {
						menuTower->name,
						std::to_string(int(menuTower->damage)),
						std::to_string(int(menuTower->range)),
						std::to_string(int(menuTower->firerate)),
						std::to_string(menuTower->value)
					};

					towerInfoMenu infoTower = menuSide.getMoveableMenu();
					infoTower.updateStrings( textInTextObjects );

					menuSide.showInfoTowerMenu = true;

					return;
				}
			}
			menuSide.showInfoTowerMenu = false;

			// Check if the mouse is looking at a button
			std::vector<button*> buttons = menuSide.getButtons();
			for ( auto button : buttons ) {
				if (button->pointInButton( mousePointer )) {
					if ( button->getString() == "Upgrade" ) {
						menuSide.showUpgrades = true;
						return;
					}
				}
			}
			menuSide.showUpgrades = false;
		}
	}
}

void mouseControl::selectClick( const sf::Vector2i & mousePointer ){
	// Check if mouse is pointing at something outside the tilemap
	if ( map.getTilePosition(sf::Vector2i{mousePointer}) == sf::Vector2i{-1,-1} && menuSide.getSeletedTower() == nullptr ) {
		for ( auto &menuTower : menuSide.getTowers() ){
			if (menuTower->getGlobalBounds().contains( sf::Vector2f{ float(mousePointer.x), float(mousePointer.y) } )){
				
				// Stop further action if the player has insufficient money
				if ( menuTower->value > menuSide.getMoney() ) {
					menuSide.insufficientMoney = true;
					return;
				}

				// Deselect all towers for towerinfo
				if ( towers.towers.size() >= 1 ) {
					for ( auto &tower : towers.towers ) {
						tower->selected = false;
					}
				}

				// Deselect tower info
				menuSide.showInfoTowerMenu = false;

				// Deselect if tower is selected
				if (placeTower) {
					deselectClick();
				}

				// Make new tower which is the same as clicked
				placeTower = true;
				newTower = new tower{ 
					menuTower->name,
					(unsigned int)menuTower->damage,
					(unsigned int)menuTower->range,
					(unsigned int)menuTower->firerate,
					menuTower->getFillColor(),
					(unsigned int)menuTower->value
				};
				newTower->setSize(menuTower->getSize());

				// Add newtower to the towers vector
				towers.add(newTower);

				// Stop the for loop
				break;
			}
		}
		
	// When the tile is empty and a tower is held, place the tower
	} else if ( placeTower && availableSpot ){

		placeTower = false;
		towers.addTmpTower();
		towers.showTmpTower = false;

		sf::Vector2i tilePosition = map.getTilePosition( mousePointer );
		auto tile = map.getTileFromIndex( tilePosition );

		tile->setAllowPlacement( false );
		if ( towers.isTower( tile ) ) {
			tower* selectedTower = towers.getTower( tile );
			selectedTower->selected = false;
			menuSide.setMoney( menuSide.getMoney() - selectedTower->value );

			menuSide.setSelectedTower( nullptr );
		}

	// When the tile selected is a tower
	} else if ( !placeTower && map.getTilePosition(sf::Vector2i{ mousePointer }) != sf::Vector2i{-1,-1} ) {
		sf::Vector2i tilePosition = map.getTilePosition( mousePointer );
		auto tile = map.getTileFromIndex( tilePosition );

		if ( towers.isTower( tile ) ) {
			tower* selectedTower = towers.getTower( tile );
			menuSide.setSelectedTower( selectedTower );

			for ( auto &tower : towers.towers ) {

				// Set selected false for every tower except the one at mousepointer
				if ( tower != selectedTower ) {
					tower->selected = false;

				// Set selected false when tower at mousepointer
				} else if ( selectedTower->selected ) {
					selectedTower->selected = false;
					menuSide.setSelectedTower( nullptr );

				// Set selected true
				} else {
					selectedTower->selected = true;
				}
			}
		
		// Set selected false for all towers when mousepointer not a tower
		} else {
			menuSide.setSelectedTower( nullptr );

			if ( towers.towers.size() >= 1 ) {
				for ( auto &tower : towers.towers ) {
					tower->selected = false;
				}
			}
		}

	// When outside tilemap and there is an selected tower
	} else if ( map.getTilePosition(sf::Vector2i{mousePointer}) == sf::Vector2i{-1,-1} && menuSide.getSeletedTower() != nullptr ) {
		
		std::vector<button*> buttons = menuSide.getButtons();
		for ( auto button : buttons ) {
			if (button->pointInButton( mousePointer )) {

				// If button says Delete then
				if ( button->getString() == "Delete" ) {

					// Remove the tower which is selected and give back 80% of its value
					tower *selectedTower = menuSide.getSeletedTower();
					for ( unsigned int i = 0; i < towers.towers.size(); i++ ) {
						if ( towers.towers[i] == selectedTower ) {
							menuSide.setMoney( menuSide.getMoney() + selectedTower->value * GIVE_BACK_MULTIPLIER );

							sf::Vector2i tilePosition = map.getTilePosition( sf::Vector2i{towers.towers[i]->getPosition()} );
							auto tile = map.getTileFromIndex( tilePosition );
							tile->setAllowPlacement( true );

							towers.towers.erase( towers.towers.begin() + i );
							menuSide.setSelectedTower( nullptr );
							break;
						}
					}

				} else if ( button->getString() == "Upgrade" ) {

					// Upgrade all the stats for the tower and remove its value times multiplier from money
					tower *selectedTower = menuSide.getSeletedTower();

					if ( selectedTower->value * PAY_MULTIPLIER < menuSide.getMoney() ) {
						selectedTower->damage	*= DAMAGE_MULTIPLIER;
						selectedTower->range	*= RANGE_MULTIPLIER;
						selectedTower->value	*= PAY_MULTIPLIER;
						selectedTower->upgrade	+= 1;
						menuSide.setMoney( menuSide.getMoney() - selectedTower->value );
					}

					menuSide.showUpgrades = false;
				}
			}
		}
	}
}

void mouseControl::deselectClick() {
	placeTower = false;
	towers.clearTmpTower();
}