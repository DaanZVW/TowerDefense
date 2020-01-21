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

void tower::draw(sf::RenderWindow &window){
	// std::cout << showRange << std::endl;

	if(showRange){
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
	sf::Vector2f thisPos = getPosition();
	int rangeSize = getSize().x * range + getSize().x/2;
	float difx = std::abs(pos.x-thisPos.x);
	float dify = std::abs(pos.y-thisPos.y);
	return (rangeSize*rangeSize) > ((difx*difx) + (dify*dify));
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
		tower->draw( window );
	}
	if ( showTmpTower ) {
		tmpTower->showRange = true;
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


