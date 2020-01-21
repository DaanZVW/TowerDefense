#ifndef SHOTHANDLER_HPP
#define SHOTHANDLER_HPP

#include "tower.hpp"
#include "enemyChar.hpp"

class shotHandler{
private:
	towerGroup & towers;
	enemyCharGroup & enemies;

public:
	shotHandler( towerGroup & towers, enemyCharGroup & enemies );

	void update();
};


#endif /*SHOTHANDLER_HPP*/