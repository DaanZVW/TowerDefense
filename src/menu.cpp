#include "menu.hpp"


menuTextObject::menuTextObject(const sf::Vector2f & position, const std::string & text):
	text( text )
{
	setPosition( position );
}

menu::menu(const sf::Vector2f & position, const sf::Vector2f & size, std::vector<tower*> towers, const float &tilesize ):
	position( position ),
	size( size ),
	towers( towers ),
	tilesize( tilesize )
{
	setPosition( position );
	setSize( size );
	setFillColor( sf::Color(128, 128, 128, 100) );
	for( unsigned int i=0; i<towers.size(); i++){
		towers[i]->setPosition(sf::Vector2f{position.x+100, position.y+(i*tilesize*2)});
		towers[i]->setSize(sf::Vector2f{ tilesize,tilesize});
	}
}



void menu::draw( sf::RenderWindow &window ){
	window.draw( *this );
	for( auto &tower : towers ){
		window.draw( *tower );
	}
}