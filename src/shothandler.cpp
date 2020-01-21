#include "shothandler.hpp"

shotHandler::shotHandler( towerGroup & towers, enemyCharGroup & enemies ):
	towers( towers ),
	enemies( enemies )
{}

void shotHandler::update(){
	std::cout << towers.towers.size();
	for(auto& enemy : enemies.enemies){
		sf::Vector2f tmpEnemeyPos = enemy->getPosition();
		for(auto& tower : towers.towers){
			if(tower->inRange( tmpEnemeyPos )){
				if (tower->fireclock.getElapsedTime().asMilliseconds() > (60 / tower->getFireRate()) * 1000) {
					enemy->enemyCharHit( tower->getDamage() );
					tower->fireclock.restart();
				}
			}
		}
	}
}

