#include "menuTextObject.hpp"

menuTextObject::menuTextObject(
	const sf::Vector2f &position, 
	const std::string &text,
	const sf::Font *font, 
	int charSize = 30, 
	sf::Color color, 
	sf::Text::Style style
) {
	setFont( *font );
	setPosition( position );
	setString( text );
	setCharacterSize( charSize );
	setFillColor( color );
	setStyle( style );
}