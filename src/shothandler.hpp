#ifndef SHOTHANDLER_HPP
#define SHOTHANDLER_HPP

#include "tower.hpp"
#include "enemyChar.hpp"

class bullet : public sf::CircleShape{
private:
	tower * myTower;
	std::weak_ptr<enemyChar>  enemy;
	sf::Clock clock;


public:

	

	bullet( tower * myTower, std::weak_ptr<enemyChar>  enemy );

	void updatePos();

	void hitEnemy();

	bool intersectsEnemy();
	std::weak_ptr<enemyChar>& getTarget() { return enemy; }

};

class shotHandler{
private:
	sf::RenderWindow & window;
	towerGroup & towers;
	enemyCharGroup & enemyGroupObj;
	std::vector < std::unique_ptr<bullet> > bullets;

public:
	shotHandler( sf::RenderWindow & window, towerGroup & towers, enemyCharGroup & enemyGroupObj );

	void update();


};


#endif /*SHOTHANDLER_HPP*/