#include "menu.hpp"

// ==============================================================================
// ==============================================================================
// ==============================================================================


menu::menu(
	const sf::Vector2f & position,
	const sf::Vector2f & size, 
	std::vector<tower*> allTowers, 
	const float &tilesize, 
	const sf::Font *font,
	std::vector< sf::RectangleShape* > iconsTowerMenu,
	std::vector< sf::RectangleShape* > iconsInfoTower,
	uint32_t &money
):
	position( position ),
	size( size ),
	allTowers( allTowers ),
	tilesize( tilesize ),
	font ( font ),
	iconsTowerMenu ( iconsTowerMenu ),
	iconsInfoTower ( iconsInfoTower ),
	money ( money ),

	towerMenu{ position, size, font, (unsigned int)allTowers.size(), allTowers, tilesize },
	infoMenu{ position, size, font, 5, iconsTowerMenu, tilesize },
	infoTower{ position, sf::Vector2f{size.x/2, size.y/5}, font, 5, iconsInfoTower, tilesize, sf::Color::Black }
{	
	// Set menu texture
	setPosition( position );
	setSize( size );
	setFillColor( sf::Color(128, 128, 128, 100) );

	// Set position for the towers in bottom menu
	for( unsigned int i=0; i < allTowers.size(); i++){
		allTowers[i]->setPosition( 
			position + sf::Vector2f{ 
				float( size.x * TBM_OFFSET_X ), 
				float( size.y * TIO_OFFSET_Y + 
					i * size.y * TBM_TEXT_SPACING ) 
			});
		allTowers[i]->setSize( sf::Vector2f{ tilesize, tilesize } );
	}

	// Make top info pictures index
	std::vector<int> indexPositions{
		4,
		6,
		7
	};

	// Make top info
	for ( unsigned int i = 0; i < indexPositions.size(); i++ ) {
		// Make text object
		topInfoText.push_back( new menuTextObject{
			position + sf::Vector2f {
				float( size.x * MTI_OFFSET_X * 5 ),
				float( size.y * MTI_OFFSET_Y * 2.7 +
					i * size.y * MTI_TEXT_SPACING )
			},
			"ERROR",
			font,
			int( size.x * MTI_CHAR_DEVIDER )
		});

		// Make texture
		sf::RectangleShape *picture = new sf::RectangleShape;
		picture->setPosition(
			float( position.x + size.x * MTI_OFFSET_X ),
			float( position.y + size.y * MTI_OFFSET_Y + 
				i * size.y * MTI_TEXT_SPACING )
		);
		picture->setSize( sf::Vector2f{ tilesize, tilesize } );
		picture->setTexture( iconsInfoTower[indexPositions[i]]->getTexture() );
		topInfoIcons.push_back( picture );
	}

	// Make splitline between topinfo and bottom info
	splitLine.setPosition( sf::Vector2f{ position.x, float(position.y + size.y * MTI_SPLIT_LINE_Y) } );
	splitLine.setSize( sf::Vector2f{ size.x, float(size.y * MTI_OFFSET_Y)} );
	splitLine.setFillColor( sf::Color::White );

	// Make buttons
	std::vector< std::pair< std::string, sf::Color > > textInButtons {
		std::pair<std::string, sf::Color>{ "Upgrade", sf::Color::Green },
		std::pair<std::string, sf::Color>{ "Delete", sf::Color::Red },
	};
	for ( unsigned int i = 0; i < 2; i++ ) {
		button *buttonObj = new button{ 
			position + sf::Vector2f{ float(size.x * MTI_OFFSET_X + i * size.x/2), float(size.y/1.13) }, 
			sf::Vector2f{ 200, 100 }, 
			textInButtons[i].first, 
			font, 
			textInButtons[i].second
		};
		buttons.push_back( buttonObj );
	}

	// Restart the clock
	clock.restart();
}

// ==============================================================================

void menu::draw( sf::RenderWindow &window ){
	// Draw the window itself
	window.draw( *this );

	// Draw the splitline between top info and bottom info
	window.draw( splitLine );

	// If a second has passed add a second to timePlayed
	if ( sf::Time( clock.getElapsedTime() ).asSeconds() > 1 ) {
		clock.restart();
		timePlayed++;
	}

	// Make a vector for the top information
	std::vector<std::string> TextForTopText {
		std::to_string( money ),
		std::to_string( timePlayed ),
		std::to_string( currentWave )
	};

	// Set the text for the topInfo and draw the picture and text
	for ( unsigned int i = 0; i < topInfoText.size(); i++ ) {
		topInfoText[i]->setString( TextForTopText[i] );
		window.draw( *topInfoText[i] );
		window.draw( *topInfoIcons[i] );
	}

	if( selectedTower == nullptr ) {
		// Update the strings of the selected Tower
		std::vector<std::string> textInTextObjects;
		for ( auto tower : allTowers ) { 
			textInTextObjects.push_back( tower->name );
		}
		towerMenu.updateStrings( textInTextObjects );
		
		// Draw the towers and the text
		for( auto towerObj : allTowers ){
			window.draw( *towerObj );
		}
		towerMenu.draw( window );



		// Draw tower info when hovering over it
		if ( showInfoTowerMenu ) {

			// Draw the menu
			window.draw( infoTower );

			// If play has insufficient money, make cost red
			if ( insufficientMoney ) {
				infoTower.updateColor( 4, sf::Color::Red );
			} else {
				infoTower.updateColor( 4, infoTower.getOriginalColor() );
			}

			// Update the positions of the menu to the mouse position
			infoTower.updateObjectPositions( iconsInfoTower, sf::Mouse::getPosition( window ) );
			
			// Draw the icons
			for ( auto icon : iconsInfoTower ) {
				window.draw( *icon );
			}

			// Draw the text objects
			infoTower.draw( window );
		}
	


	// Show tower information on the menu
	} else {
		// Draw all the buttons
		for ( auto buttonObj : buttons ) {
			buttonObj->draw( window );
		}
		
		if ( showUpgrades ) {
			// Make the vector with strings for the objects	
			std::vector<std::string> textInTextObjects {
				selectedTower->name,
				std::to_string(int(selectedTower->damage)) + " -> " + std::to_string(int(selectedTower->damage * DAMAGE_MULTIPLIER)),
				std::to_string(int(selectedTower->range)) + " -> " + std::to_string(int(selectedTower->range * RANGE_MULTIPLIER)),
				std::to_string(int(selectedTower->firerate)),
				std::to_string(int(selectedTower->upgrade)) + " -> " + std::to_string(int(selectedTower->upgrade + 1))
			};

			// Update all the strings according to the vector
			infoMenu.updateStrings( textInTextObjects );
		
		} else {
			// Make the vector with strings for the objects	
			std::vector<std::string> textInTextObjects {
				selectedTower->name,
				std::to_string(int(selectedTower->damage)),
				std::to_string(int(selectedTower->range)),
				std::to_string(int(selectedTower->firerate)),
				std::to_string(int(selectedTower->upgrade))
			};

			// Update all the strings according to the vector
			infoMenu.updateStrings( textInTextObjects );
		}

		// Print the icons
		for( unsigned int i = 0; i < 5; i ++ ){
			window.draw( *iconsTowerMenu[i] );
		}

		// Print the text objects
		infoMenu.draw( window );
	}
}

// ==============================================================================

std::vector<tower*> menu::getTowers(){
	return allTowers;
}

// ==============================================================================

void menu::setSelectedTower( tower* towerPointer ) {
	selectedTower = towerPointer;
}

// ==============================================================================

tower* menu::getSeletedTower(){
	return selectedTower;
}

towerInfoMenu menu::getMoveableMenu() {
	return infoTower;
}

// ==============================================================================

uint32_t menu::getMoney() {
	return money;
}

// ==============================================================================

void menu::setMoney( const uint32_t &newValue ) {
	money = newValue;
}

// ==============================================================================

std::vector<button*> menu::getButtons() {
	return buttons;
}
