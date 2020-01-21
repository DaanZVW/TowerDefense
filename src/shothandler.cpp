#include "shothandler.hpp"


bullet::bullet( const sf::Vector2f & beginPos, const sf::Vector2f & endPos, const int & size ):
	endPos( endPos )
{
	// setPosition( beginPos );
	// setRadius( size );
	// setOrigin( size, size );
	// setFillColor( sf::Color::Blue );
}


shotHandler::shotHandler( towerGroup & towers, enemyCharGroup & enemies ):
	towers( towers ),
	enemies( enemies )
{}

void shotHandler::update(){
	for(auto& enemy : enemies.enemies){
		sf::Vector2f tmpEnemeyPos = enemy->getPosition();
		for(auto& tower : towers.towers){
			if(tower->inRange( tmpEnemeyPos )){
				if (tower->fireclock.getElapsedTime().asMilliseconds() > (60 / tower->getFireRate()) * 1000) {
					enemy->enemyCharHit( tower->getDamage() );
					bullets.push_back( new bullet{tower->getPosition(), enemy->getPosition(), 5} );
					tower->fireclock.restart();
				}
			}
		}
	}
}

