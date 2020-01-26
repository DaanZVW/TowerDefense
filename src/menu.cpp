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
	const sf::Font *font,
	int amount,
	sf::Color color = sf::Color::White, 
	sf::Text::Style style = sf::Text::Bold
):
	position ( position ),
	font ( font ),
	amount ( amount ),
	color ( color ),
	style ( style )
{
	for ( int i = 0; i < amount; i++ ) {
		std::cout << i << std::endl;
		textObjects.push_back( 
			new menuTextObject{
				position + sf::Vector2f{ 
					float( sf::VideoMode::getDesktopMode().width  * TIO_OFFSET_X ), 
					float( sf::VideoMode::getDesktopMode().height * TIO_OFFSET_Y + 
						i * sf::VideoMode::getDesktopMode().height * TIO_TEXT_DEVIDER ) 
				},
				"ERROR",
				font,
				int( sf::VideoMode::getDesktopMode().width * TIO_CHARSIZE_DEVIDER ),
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



// ==============================================================================
// ==============================================================================
// ==============================================================================


menu::menu(
	const sf::Vector2f & position, 
	const sf::Vector2f & size, 
	std::vector<tower*> allTowers, 
	const float &tilesize, 
	const sf::Font *font 
):
	position( position ),
	size( size ),
	allTowers( allTowers ),
	tilesize( tilesize ),
	font ( font ),
	infoMenu{ position, font, 4 }
{
	setPosition( position );
	setSize( size );
	setFillColor( sf::Color(128, 128, 128, 100) );
	for( unsigned int i=0; i<allTowers.size(); i++){
		allTowers[i]->setPosition(sf::Vector2f{position.x+100, position.y+(i*tilesize*2)});
		allTowers[i]->setSize(sf::Vector2f{ tilesize,tilesize});
	}
}

void menu::draw( sf::RenderWindow &window ){
	window.draw( *this );

	switch ( (selectedTower == nullptr) ) {
		case true:
		{
			for( auto tower : allTowers ){
				window.draw( *tower );
			}
			break;
		}
		
		case false:
		{	
			std::vector<std::string> textInTextObjects {
				"Name : " + selectedTower->name,
				"Range : " + std::to_string(selectedTower->range),
				"Damage : " + std::to_string(selectedTower->damage),
				"Firerate : " + std::to_string(selectedTower->firerate),
			};

			infoMenu.updateStrings( textInTextObjects );
			infoMenu.draw( window );

			break;
		}
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