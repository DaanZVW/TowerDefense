#include "menu.hpp"

menuTextObject::menuTextObject(
	const sf::Vector2f &position, 
	const std::string &text,
	const sf::Font *font, 
	int charSize = 30, 
	sf::Color color = sf::Color::White, 
	sf::Text::Style style = sf::Text::Bold
) {
	setFont( *font );
	setPosition( position );
	setString( text );
	setCharacterSize( charSize );
	setFillColor( color );
	setStyle( style );
}

// ==============================================================================
// ==============================================================================
// ==============================================================================

towerInfoMenu::towerInfoMenu(
	sf::Vector2f position,
	sf::Vector2f menuSize, 
	const sf::Font *font,
	unsigned int amount,
	std::vector< tower* > &allTowers,
	const float &tileSize,
	sf::Color color = sf::Color::White, 
	sf::Text::Style style = sf::Text::Bold
):
	position ( position ),
	menuSize ( menuSize ),
	font ( font ),
	amount ( amount ),
	tileSize ( tileSize ),
	color ( color ),
	style ( style )
{
	for ( unsigned int i = 0; i < amount; i++ ) {
		allTowers[i]->setPosition(
			position + sf::Vector2f {
				float( menuSize.x * TBM_OFFSET_X ),
				float( menuSize.y * TIO_OFFSET_Y +
					i * menuSize.y * TBM_TEXT_SPACING )
			}	
		);
		allTowers[i]->setSize( sf::Vector2f{ tileSize, tileSize } );

		textObjects.push_back( 
			new menuTextObject{
				position + sf::Vector2f{ 
					float( (menuSize.x * TIO_OFFSET_X) * 2 ), 
					float( (menuSize.y * TIO_OFFSET_Y) * 1.05 + 
						i * menuSize.y * TBM_TEXT_SPACING ) 
				},
				"ERROR",
				font,
				int( menuSize.y * TIO_CHARSIZE_DEVIDER ),
				color,
				style
			}
		);
	}
	
}

towerInfoMenu::towerInfoMenu(
	sf::Vector2f position,
	sf::Vector2f menuSize, 
	const sf::Font *font,
	unsigned int amount,
	std::vector< sf::RectangleShape* > &allpictures,
	const float &tileSize,
	sf::Color color = sf::Color::White, 
	sf::Text::Style style = sf::Text::Bold
):
	position ( position ),
	menuSize ( menuSize ),
	font ( font ),
	amount ( amount ),
	tileSize ( tileSize ),
	color ( color ),
	style ( style )
{	
	setPosition( position );
	setSize( menuSize );
	setFillColor( sf::Color( 165, 165, 165, 225 ) );
	setOutlineThickness( 2 );
	setOutlineColor( sf::Color::Black );

	for ( unsigned int i = 0; i < amount; i++ ) {
		allpictures[i]->setPosition(
			position + sf::Vector2f {
				float( menuSize.x * TBM_OFFSET_X ),
				float( menuSize.y * TIO_OFFSET_Y +
					i * menuSize.y * TBM_TEXT_SPACING )
			}	
		);
		allpictures[i]->setSize( sf::Vector2f{ tileSize, tileSize } );

		textObjects.push_back( 
			new menuTextObject{
				position + sf::Vector2f{ 
					float( (menuSize.x * TIO_OFFSET_X) * 2 ), 
					float( (menuSize.y * TIO_OFFSET_Y) * 1.05 + 
						i * menuSize.y * TBM_TEXT_SPACING ) 
				},
				"ERROR",
				font,
				int( menuSize.y * TIO_CHARSIZE_DEVIDER ),
				color,
				style
			}
		);
	}
}

void towerInfoMenu::draw( sf::RenderWindow &window ) {
	for ( auto object : textObjects ) {
		window.draw( *object );
	}
}

void towerInfoMenu::updateStrings( const std::vector<std::string> &textInTextObjects ) {
	for ( unsigned int i = 0; i < textObjects.size(); i++ ) {
		textObjects[i]->setString( textInTextObjects[i] );
	}
}

void towerInfoMenu::updateObjectPositions( std::vector< sf::RectangleShape* > &allpictures, const sf::Vector2i &tPosition ) {
	position = sf::Vector2f{tPosition};
	setPosition( sf::Vector2f{tPosition} );

	for ( unsigned int i = 0; i < amount; i++ ) {
		allpictures[i]->setPosition(
			position + sf::Vector2f {
				float( menuSize.x * TBM_OFFSET_X ),
				float( TIO_OFFSET_X * 10 + i * menuSize.y * TIM_TEXT_SPACING )
			}	
		);
		allpictures[i]->setSize( sf::Vector2f{ menuSize.x/PICTURE_SIZE_DEVIDER, menuSize.x/PICTURE_SIZE_DEVIDER } );

		textObjects[i]->setPosition(
			position + sf::Vector2f{ 
				float( menuSize.x * TIM_OFFSET_X ), 
				float( TIM_OFFSET_X * 30 + i * menuSize.y * TIM_TEXT_SPACING )
			}
		);
		textObjects[i]->setCharacterSize( menuSize.y * TIM_CHARSIZE_DEVIDER );
	}
}



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
	towerMenu{ position, size, font, (uint)allTowers.size(), allTowers, tilesize },
	infoMenu{ position, size, font, 4, iconsTowerMenu, tilesize },
	infoTower{ position, sf::Vector2f{size.x/2, size.y/5}, font, 5, iconsInfoTower, tilesize, sf::Color::Black }
{
	setPosition( position );
	setSize( size );
	setFillColor( sf::Color(128, 128, 128, 100) );

	clock.restart();

	for( unsigned int i=0; i < allTowers.size(); i++){
		allTowers[i]->setPosition( 
			position + sf::Vector2f{ 
				float( size.x * TBM_OFFSET_X ), 
				float( size.y * TIO_OFFSET_Y + 
					i * size.y * TBM_TEXT_SPACING ) 
			});
		allTowers[i]->setSize( sf::Vector2f{ tilesize, tilesize } );
	}

	for ( uint i = 0; i < 2; i++ ) {
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
		picture->setTexture( iconsTowerMenu[i+4]->getTexture() );
		topInfoIcons.push_back( picture );
	}
	splitLine.setPosition( sf::Vector2f{ position.x, float(position.y + size.y * MTI_SPLIT_LINE_Y) } );
	splitLine.setSize( sf::Vector2f{ size.x, float(size.y * MTI_OFFSET_Y)} );
	splitLine.setFillColor( sf::Color::White );
}

void menu::draw( sf::RenderWindow &window ){
	window.draw( *this );
	window.draw( splitLine );

	if ( sf::Time( clock.getElapsedTime() ).asSeconds() > 1 ) {
		clock.restart();
		timePlayed++;
	}

	std::vector<std::string> TextForTopText {
		std::to_string( money ),
		std::to_string( timePlayed )
	};

	for ( uint i = 0; i < topInfoText.size(); i++ ) {
		topInfoText[i]->setString( TextForTopText[i] );
		window.draw( *topInfoText[i] );
	}

	for ( auto iconObj : topInfoIcons ) {
		window.draw( *iconObj );
	}

	if(selectedTower == nullptr) {
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
			window.draw( infoTower );

			infoTower.updateObjectPositions( iconsInfoTower, sf::Mouse::getPosition( window ) );
			for ( auto icon : iconsInfoTower ) {
				window.draw( *icon );
			}
			infoTower.draw( window );
		}

	} else {	
		std::vector<std::string> textInTextObjects {
			selectedTower->name,
			std::to_string(selectedTower->damage),
			std::to_string(selectedTower->range),
			std::to_string(selectedTower->firerate)
		};
		infoMenu.updateStrings( textInTextObjects );

		for( unsigned int i = 0; i < 4; i ++ ){
			window.draw( *iconsTowerMenu[i] );
		}

		infoMenu.draw( window );
	}
}

std::vector<tower*> menu::getTowers(){
	return allTowers;
}

void menu::setSelectedTower( tower* towerPointer ) {
	selectedTower = towerPointer;
}

tower* menu::getSeletedTower(){
	return selectedTower;
}

towerInfoMenu menu::getMoveableMenu() {
	return infoTower;
}

uint32_t menu::getMoney() {
	return money;
}

void menu::setMoney( const uint32_t &newValue ) {
	money = newValue;
	// std::cout << money << std::endl;
}
