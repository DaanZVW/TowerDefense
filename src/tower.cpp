#include "tower.hpp"

tower::tower( 
	const std::string & name, 
	const unsigned int & damage, 
	const unsigned int & range, 
	const unsigned int & firerate, 
	const std::string & texture, 
	const unsigned int &value = 0
):
	name( name ),
	damage( damage ),
	range( range ),
	firerate( firerate ),
	value( value )
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

tower::tower(
	const std::string & name, 
	const unsigned int & damage, 
	const unsigned int & range, 
	const unsigned int & firerate, 
	const sf::Color & color,
	const unsigned int &value = 0
):
	name( name ),
	damage( damage ),
	range( range ),
	firerate( firerate ),
	value( value )
{
	setFillColor( color );
	mycolor = getFillColor();
}

void tower::draw(sf::RenderWindow &window){
	if(selected){
		sf::CircleShape towerRange;
		int rangeSize = getSize().x * range + getSize().x/2;
		towerRange.setFillColor(sf::Color(160, 160,160, 100));
		towerRange.setPosition(getPosition().x+ (getSize().x/2), getPosition().y + getSize().y/2);
		towerRange.setOrigin(rangeSize, rangeSize);
		towerRange.setRadius(rangeSize);
		window.draw(towerRange);
	}
	window.draw( *this );
}

int tower::getDamage(){
	return damage;
}

bool tower::inRange( const sf::Vector2f & pos ){
	sf::Vector2f thisPos{getPosition().x+ (getSize().x/2), getPosition().y + getSize().y/2};
	int rangeSize = getSize().x * range + getSize().x/2;
	float difx = std::abs(pos.x-thisPos.x);
	float dify = std::abs(pos.y-thisPos.y);

	if ((rangeSize*rangeSize) > ((difx*difx) + (dify*dify))) {
		// setFillColor( sf::Color::Red );
		return true;
	} else {
		setFillColor( mycolor );
		return false;
	}
}

int tower::getFireRate(){
	return firerate;
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

bool towerGroup::towersInRange( const sf::Vector2f & pos ){
	for( auto tower : towers ){
		if(tower->inRange(pos)){
			return true;
		}
	}
	return false;
}


