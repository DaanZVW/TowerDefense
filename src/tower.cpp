#include "tower.hpp"


tower::tower( const std::string & name, 
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
		setFillColor(sf::Color::Cyan);
	}else if(texture == "Aqua"){
		setFillColor(sf::Color::White);
	}
	mycolor = getFillColor();
}

tower::tower( const std::string & name, 
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

// ==============================================================
// ==============================================================
// ==============================================================

towerGroup::towerGroup(){}

void towerGroup::add(tower* & newTower ){
	tmpTower = newTower;
	showTmpTower = true;
}

void towerGroup::addTmpTower(){
	towers.push_back( tmpTower );
}

void towerGroup::clearTmpTower() {
	showTmpTower = false;
}

bool towerGroup::isTower( tile* &checkTower ) {
	for ( auto tower : towers ){ 
		if ( checkTower->getPosition().x == tower->getPosition().x && checkTower->getPosition().y == tower->getPosition().y ) {
			return true;
		}
	}
	return false;
}

tower* towerGroup::getTower( tile* &checkTower ) {
	for ( auto tower : towers ){ 
		if ( checkTower->getPosition().x == tower->getPosition().x && checkTower->getPosition().y == tower->getPosition().y ) {
			return tower;
		}
	}
	return towers[0];
}

void towerGroup::draw( sf::RenderWindow &window ){
	for(auto tower : towers ){
		window.draw( *tower );
	}
	if ( showTmpTower ) {
		window.draw( *tmpTower );
	}
}



