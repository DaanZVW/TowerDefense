#include "menu.hpp"

menu::menu(const sf::Vector2f & position, const sf::Vector2f & size ):
	position( position ),
	size( size )
{
	setPosition( position );
	setSize( size );
	setFillColor( sf::Color(128, 128, 128, 100) );
}


menuTowerObject::menuTowerObject(const sf::Vector2f & position, const sf::Vector2f & size )
{
	setPosition( position );
	setSize( size);

}

menuTextObject::menuTextObject(const sf::Vector2f & position, const std::string & text):
	text( text )
{
	setPosition( position );
}