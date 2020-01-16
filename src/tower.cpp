#include "tower.hpp"




// void tower::towerGroup( const sf::Vector2i & mousePosition){
// 	sf::Vector2i tilePosition = map.getTilePosition( mousePosition );
// 	auto tile = map.getTileFromIndex( tilePosition );

// 	setPosition( tile->getPosition() );
// 	setSize( tile->getSize() );

// 	if( tile->getAllowPlacement() ){
// 		setFillColor( sf::Color::Blue );
// 	}else{
// 		setFillColor( sf::Color::Red );
// 	}

// }




tower::tower( 	const std::string & name, 
				const int & damage, 
				const int & range, 
				const int & firerate,
				const std::string & texture
			):
	name( name ),
	damage( damage ),
	range( range ),
	firerate( firerate )
{
	std::cout << texture;
	if(texture == "Black"){
		setFillColor(sf::Color::Black);
	}else if(texture == "Blue"){
		setFillColor(sf::Color::Blue);
	}else if(texture == "Yellow"){
		setFillColor(sf::Color::Yellow);
	}
}

