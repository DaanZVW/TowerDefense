#include "mousecontrol.hpp"

mouseControl::mouseControl( tilemap & map, menu & menuSide, towerGroup & towers):
	map( map ),
	menuSide( menuSide ),
	towers( towers )
{}

void mouseControl::updateMouse( const sf::Vector2i & mousePointer ){
	if(placeTower == true ){
		if( map.getTilePosition(sf::Vector2i{mousePointer}) == sf::Vector2i{-1,-1} ){
			newTower->setPosition(sf::Vector2f{float(mousePointer.x), float(mousePointer.y)});
		}else{
			sf::Vector2i tilePosition = map.getTilePosition( mousePointer );
			auto tile = map.getTileFromIndex( tilePosition );
			sf::Color color = newTower->getFillColor();

			newTower->setPosition( tile->getPosition() );
			newTower->setSize( tile->getSize() );

			if( tile->getAllowPlacement() ){
				newTower->setFillColor( newTower->mycolor );
			}else{
				newTower->setFillColor( sf::Color::Red );
			}




		}
	}
}

void mouseControl::mouseClick( const sf::Vector2i & mousePointer ){
	if( map.getTilePosition(sf::Vector2i{mousePointer}) == sf::Vector2i{-1,-1} ){
		for( auto menuTower : menuSide.getTowers() ){
			if(menuTower->getGlobalBounds().contains( sf::Vector2f{ float(mousePointer.x), float(mousePointer.y) } )){
				placeTower=true;
				newTower = new tower{ 
								menuTower->name,
								menuTower->damage,
								menuTower->range,
								menuTower->firerate,
								menuTower->getFillColor()
								};
				newTower->setSize(menuTower->getSize());
				towers.add(newTower);
			}
		}
	}	
}