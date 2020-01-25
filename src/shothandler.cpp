#include "shothandler.hpp"
#include <math.h>

bullet::bullet( tower * myTower, std::unique_ptr<enemyChar> & enemy ):
	myTower( myTower ),
	enemy( enemy )
{
	sf::Vector2f beginPos = myTower->getPosition();
	int tileSize = myTower->getSize().x;
	setPosition( beginPos.x+(tileSize/2), beginPos.y+(tileSize/2));
	setRadius( tileSize/8 );
	setOrigin( tileSize/8, tileSize/8 );
	setFillColor( sf::Color::Black );
}

void bullet::updatePos(){

	if(clock.getElapsedTime().asMilliseconds() > (10)){
		if(enemy){

			sf::Vector2f difxy = {
				enemy->getPosition().x - getPosition().x,
				enemy->getPosition().y - getPosition().y
			};

			float speed = myTower->getSize().x/2;

			float dif = sqrt( (difxy.x*difxy.x) + (difxy.y*difxy.y) );

			sf::Vector2f direction{ 
				difxy.x / (dif / speed), 
				difxy.y / (dif / speed) 
			};

			setPosition( getPosition()+direction  );

	}
		
		clock.restart();

	}
}

void bullet::hitEnemy(){
	enemy->enemyCharHit( myTower->getDamage() );
}

bool bullet::intersectsEnemy(){
	return getGlobalBounds().intersects( enemy->getGlobalBounds());
}

shotHandler::shotHandler( sf::RenderWindow & window, towerGroup & towers, enemyCharGroup & enemies ):
	window( window ),
	towers( towers ),
	enemies( enemies )
{}

void shotHandler::update(){
	// for(auto& enemy : enemies.getEnemies()){
	// 	sf::Vector2f tmpEnemeyPos = enemy->getPosition();
	// 	for(auto& tower : towers.towers){
	// 		if(tower->inRange( tmpEnemeyPos )){
	// 			if (tower->fireclock.getElapsedTime().asMilliseconds() > (60 / tower->getFireRate()) * 100) {
	// 				bullets.push_back( new bullet( tower, enemy ) );
	// 				enemy->setFillColor( sf::Color::Red );
	// 				tower->fireclock.restart();
	// 			}
	// 		}
	// 	}
	// }
	// for( unsigned int i=0; i<bullets.size(); i++ ){
	// 	bullets[i]->updatePos();
	// 	if(bullets[i]->intersectsEnemy()){
	// 			bullets[i]->hitEnemy();
	// 			bullets.erase(bullets.begin() + i);
	// 	}
	// 	window.draw( *bullets[i] );

	// }
}


