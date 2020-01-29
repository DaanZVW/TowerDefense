#include "shothandler.hpp"
#include <math.h>

bullet::bullet( tower * myTower, std::weak_ptr<enemyChar>  enemy ):
	myTower( myTower ),
	enemy( enemy )
{
	sf::Vector2f beginPos = myTower->getPosition();
	int tileSize = myTower->getSize().x;
	setPosition( beginPos.x+(tileSize/2), beginPos.y+(tileSize/2));
	setSize( sf::Vector2f{float(tileSize/3), float(tileSize/3 )} );
	setOrigin( tileSize/3/2, tileSize/3/2);
	setTexture(myTower->bulletTexture);
}

void bullet::updatePos(){
	if(clock.getElapsedTime().asMilliseconds() > (10)){
		if (auto tmpEnemyPtr = enemy.lock()) {
			sf::Vector2f difxy = {
				tmpEnemyPtr->getPosition().x - getPosition().x,
				tmpEnemyPtr->getPosition().y - getPosition().y
			};

			float speed = myTower->getSize().x/2;

			float dif = sqrt( (difxy.x*difxy.x) + (difxy.y*difxy.y) );

			move(difxy.x / (dif / speed), difxy.y / (dif / speed));
		}	
		clock.restart();
	}
}

int bullet::getDamage(){
	return myTower->damage;

}

bool bullet::intersectsEnemy(){
	if (auto tmpEnemyPtr = enemy.lock()) {
		return getGlobalBounds().intersects(tmpEnemyPtr->getGlobalBounds());
	}
	return false;
}

shotHandler::shotHandler( sf::RenderWindow & window, towerGroup & towers, enemyCharGroup & enemyGroupObj):
	window( window ),
	towers( towers ),
	enemyGroupObj( enemyGroupObj )
{}

void shotHandler::update(){
	std::shared_ptr<enemyChar> tmpEnemy;
	for(auto& tower : towers.towers){
		float distance = 0;
		if (tower->fireclock.getElapsedTime().asMilliseconds() > (60 / tower->firerate) * 100){
			for(auto& enemy : enemyGroupObj.getEnemies()){
				sf::Vector2f tmpEnemeyPos = enemy->getPosition();
				if(tower->inRange( tmpEnemeyPos )){
					if(enemy->tileSteps>distance){
						distance = enemy->tileSteps;
						tmpEnemy = enemy;
					}
				}
			}
			if(distance!=0){
				bullets.push_back(std::make_unique< bullet >( tower, tmpEnemy ) );
				tower->fireclock.restart();
			}
		}
	}

	
	
	for (unsigned int i = 0; i < bullets.size(); i++) {
		if (!bullets[i].get()->getTarget().expired()){
			bullets[i]->updatePos();
			window.draw(*bullets[i]);
			if (bullets[i]->intersectsEnemy()) {
				enemyGroupObj.damageEnemy(bullets[i].get()->getTarget(), bullets[i].get()->getDamage());
				bullets.erase(bullets.begin() + i);
			}
		}
		else {
			bullets.erase(bullets.begin() + i);
		}
	}
	
}


