#ifndef SHOTHANDLER_HPP
#define SHOTHANDLER_HPP

#include "tower.hpp"
#include "enemyChar.hpp"

class bullet : public sf::CircleShape{
private:
	tower * myTower;
	std::unique_ptr<enemyChar> & enemy;
	sf::Clock clock;


public:

	

	bullet( tower * myTower, std::unique_ptr<enemyChar> & enemy );

	void updatePos();

	void hitEnemy();

	bool intersectsEnemy();

};

class shotHandler{
private:
	sf::RenderWindow & window;
	towerGroup & towers;
	enemyCharGroup & enemies;
	std::vector< bullet* > bullets;

public:
	shotHandler( sf::RenderWindow & window, towerGroup & towers, enemyCharGroup & enemies );

	void update();


};


#endif /*SHOTHANDLER_HPP*/