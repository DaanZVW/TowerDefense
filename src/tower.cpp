#include "tower.hpp"

void tower::placeTower( const sf::Vector2i & mousePosition){
	sf::Vector2i tilePosition = map.getTilePosition( mousePosition );
	auto tile = map.getTileFromIndex( tilePosition );

	setPosition( tile->getPosition() );
	setSize( tile->getSize() );

	if( tile->getAllowPlacement() ){
		setFillColor( sf::Color::Blue );
	}else{
		setFillColor( sf::Color::Red );
	}

}

