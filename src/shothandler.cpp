#include "shothandler.hpp"

shotHandler::shotHandler( towerGroup & towers, enemyCharGroup & enemies ):
	towers( towers ),
	enemies( enemies )
{}

void shotHandler::update(){
	std::cout << towers.towers.size();
	for(unsigned int i=0; i<enemies.enemies.size(); i++){
		sf::Vector2f tmpEnemeyPos = enemies.enemies[i]->getPosition();
		for(unsigned int j=0; j<towers.towers.size(); j++){
			if(towers.towers[j]->inRange( tmpEnemeyPos )){
				if (towers.towers[i]->fireclock.getElapsedTime().asSeconds() > 1) {
					enemies.enemies[i]->enemyCharHit( towers.towers[i]->getDamage() );
					towers.towers[i]->fireclock.restart();
					return;
				}
			}
		}
	}
}