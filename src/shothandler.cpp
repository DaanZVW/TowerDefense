#include "shothandler.hpp"


bullet::bullet( const sf::Vector2f & beginPos, const sf::Vector2f & endPos, const int & tileSize ):
	endPos( endPos ),
	tileSize( tileSize )
{
	setPosition( beginPos.x+(tileSize/2), beginPos.y+(tileSize/2));
	setRadius( tileSize/8 );
	setOrigin( tileSize/8, tileSize/8 );
	setFillColor( sf::Color::Black );

	// // float dify = endPos.y - (beginPos.y+(tileSize/2));
	// // float difx = endPos.x - (beginPos.x+(tileSize/2));
	// // float x = dify/difx;
	// // direction = sf::Vector2f{ -1*10, -x*10 };
	// // // std::cout << dify << " " << difx << " " << x << "\n";

	// float dify = endPos.y - (beginPos.y+(tileSize/2));
	// float difx = endPos.x - (beginPos.x+(tileSize/2));

	// float x, y;
	// if ( !difx && dify ) {
	// 	x = (dify < 0) ? -1 : 1;
	// 	y = 0;
	// } else if ( difx && !dify ) {
	// 	x = 0;
	// 	y = (difx < 0) ? 1 : -1;
	// } else {
	// 	x = dify/difx;
	// 	y = 1;
	// }



	float dify = endPos.y - (beginPos.y+(tileSize/2));
	float difx = endPos.x - (beginPos.x+(tileSize/2));

	int maxMove = tileSize/8;
	float x, y;

	if ( difx > dify ) {
		x = maxMove;
		y = (maxMove / dify) * difx; 
	} else {
		x = (maxMove / difx) * dify;
		y = maxMove;
	}

	direction = sf::Vector2f{ -y, -x };
	std::cout << dify << " " << difx << " " << x << "\n";
}

void bullet::updatePos(){
	if(clock.getElapsedTime().asMilliseconds() > (10)){
		setPosition( getPosition().x + direction.x, getPosition().y + direction.y );
		clock.restart();
	}
	if(endPos == getPosition()){

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

