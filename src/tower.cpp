#include "tower.hpp"

tower::tower( 
	const std::string & name, 
	const unsigned int & damage, 
	const unsigned int & range, 
	const unsigned int & firerate, 
	const sf::Texture * texture, 
	const unsigned int &value = 0
):
	name( name ),
	damage( damage ),
	range( range ),
	firerate( firerate ),
	value( value )
{
	setTexture( texture );
}


void tower::draw(sf::RenderWindow &window){
	if(selected){
		sf::CircleShape towerRange;
		int rangeSize = getSize().x * (int)range + getSize().x/2;
		towerRange.setFillColor(sf::Color(160, 160,160, 100));
		towerRange.setPosition(getPosition().x+ (getSize().x/2), getPosition().y + getSize().y/2);
		towerRange.setOrigin(rangeSize, rangeSize);
		towerRange.setRadius(rangeSize);
		window.draw(towerRange);
	}
	window.draw( *this );
}

bool tower::inRange( const sf::Vector2f & pos ){
	sf::Vector2f thisPos{getPosition().x+ (getSize().x/2), getPosition().y + getSize().y/2};
	int rangeSize = getSize().x * (int)range + getSize().x/2;
	float difx = std::abs(pos.x-thisPos.x);
	float dify = std::abs(pos.y-thisPos.y);

	if ((rangeSize*rangeSize) > ((difx*difx) + (dify*dify))) {
		// setFillColor( sf::Color::Red );
		return true;
	} else {
		return false;
	}
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
	return 0;
}

void towerGroup::draw( sf::RenderWindow &window ){
	for(auto tower : towers ){
		tower->draw( window );
	}
	if ( showTmpTower ) {
		tmpTower->selected = true;
		tmpTower->draw( window );
	}
}



