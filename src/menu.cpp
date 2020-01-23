#include "menu.hpp"

menuTextObject::menuTextObject(const sf::Vector2f & position, const std::string & text, const sf::Font &font):
	text( text ),
	font ( font )
{
	setPosition( position );
}

menu::menu(const sf::Vector2f & position, const sf::Vector2f & size, std::vector<tower*> allTowers, const float &tilesize, const sf::Font &font ):
	position( position ),
	size( size ),
	allTowers( allTowers ),
	tilesize( tilesize ),
	font ( font )
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
	for( auto &tower : allTowers ){
		window.draw( *tower );
	}
}

std::vector<tower*> menu::getTowers(){
	return allTowers;
}