#include "menu.hpp"


menuTextObject::menuTextObject(const sf::Vector2f & position, const std::string & text):
	text( text )
{
	setPosition( position );
}

menu::menu(const sf::Vector2f & position, const sf::Vector2f & size, const std::vector<tower*> & towers ):
	position( position ),
	size( size ),
	towers( towers )
{
	setPosition( position );
	setSize( size );
	setFillColor( sf::Color(128, 128, 128, 100) );
	for( int i=0; i<towers.size(); i++){
		towers[i]->setPosition(sf::Vector2f{position.x+100, position.y+(i*40)});
		towers[i]->setSize(sf::Vector2f{20,20});
	}
}



void menu::draw( sf::RenderWindow &window ){
	for( auto tower : towers ){
		window.draw( *tower );
	}
	window.draw( *this );
}