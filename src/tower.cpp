#include "tower.hpp"

void towerGroup::add(tower* & newTower ){
	towers.push_back(newTower);
}




towerGroup::towerGroup(){}

void towerGroup::draw( sf::RenderWindow &window ){
	for(auto tower : towers ){
		window.draw( *tower );
	}
}

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
	if(texture == "Black"){
		setFillColor(sf::Color::Black);
	}else if(texture == "Blue"){
		setFillColor(sf::Color::Blue);
	}else if(texture == "Yellow"){
		setFillColor(sf::Color::Yellow);
	}
	mycolor = getFillColor();
}

tower::tower( 	const std::string & name, 
				const int & damage, 
				const int & range, 
				const int & firerate,
				const sf::Color & color
			):
	name( name ),
	damage( damage ),
	range( range ),
	firerate( firerate )
{
	setFillColor( color );
	mycolor = getFillColor();
}



