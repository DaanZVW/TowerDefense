#include "towerInfoMenu.hpp"

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
	sf::Color color, 
	sf::Text::Style style
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

// ==============================================================================

towerInfoMenu::towerInfoMenu(
	sf::Vector2f position,
	sf::Vector2f menuSize, 
	const sf::Font *font,
	unsigned int amount,
	std::vector< sf::RectangleShape* > &allpictures,
	const float &tileSize,
	sf::Color color, 
	sf::Text::Style style
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

// ==============================================================================

void towerInfoMenu::draw( sf::RenderWindow &window ) {
	for ( auto object : textObjects ) {
		window.draw( *object );
	}
}

// ==============================================================================

void towerInfoMenu::updateStrings( const std::vector<std::string> &textInTextObjects ) {
	// std::cout << textInTextObjects.size() << " " << textObjects.size() << std::endl;
	for ( unsigned int i = 0; i < textObjects.size(); i++ ) {
		textObjects[i]->setString( textInTextObjects[i] );
	}
}

// ==============================================================================

void towerInfoMenu::updateColor( const int &index, const sf::Color &color ) {
	textObjects[index]->setFillColor( color );
}

// ==============================================================================

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

sf::Color towerInfoMenu::getOriginalColor() {
	return color;
}