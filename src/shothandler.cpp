#include "shothandler.hpp"
#include <math.h>

bullet::bullet( const sf::Vector2f & beginPos, const sf::Vector2f & endPos, const int & tileSize ):
	endPos( endPos ),
	direction( endPos ),
	tileSize( tileSize )
{
	setPosition( beginPos.x+(tileSize/2), beginPos.y+(tileSize/2));
	setRadius( tileSize/8 );
	setOrigin( tileSize/8, tileSize/8 );
	setFillColor( sf::Color::Black );

	float difx = endPos.x - beginPos.x;
	float dify = endPos.y - beginPos.y;

	float speed = tileSize/2;

	float dif = sqrt( (difx*difx) + (dify*dify) );
	float x; float y;
	x = difx / (dif / speed);
	y = dify / (dif / speed);

	direction = sf::Vector2f{ x, y };

}

void bullet::updatePos(){
	if(clock.getElapsedTime().asMilliseconds() > (10)){

		sf::Vector2f thisPos = getPosition();
		setPosition( getPosition()+direction  );
		clock.restart();
	}
}


shotHandler::shotHandler( sf::RenderWindow & window, towerGroup & towers, enemyCharGroup & enemies):
	window( window ),
	towers( towers ),
	enemies( enemies )
{}

void shotHandler::update(){
	for(auto& enemy : enemies.getEnemies()){
		sf::Vector2f tmpEnemeyPos = enemy->getPosition();
		for(auto& tower : towers.towers){
			if(tower->inRange( tmpEnemeyPos )){
				if (tower->fireclock.getElapsedTime().asMilliseconds() > (60 / tower->getFireRate()) * 1000) {
					enemy->enemyCharHit( tower->getDamage() );
					bullets.push_back( new bullet(tower->getPosition(), enemy->getPosition(), tower->getSize().x) );
					enemy->setFillColor( sf::Color::Red );
					tower->fireclock.restart();
					std::cout << bullets.size() << "\n";
				}
			}
		}
	}
	for( auto& bullet : bullets ){
		bullet->updatePos();
		window.draw( *bullet );

	}
}

