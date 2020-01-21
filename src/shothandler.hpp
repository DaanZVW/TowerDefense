#ifndef SHOTHANDLER_HPP
#define SHOTHANDLER_HPP

#include "tower.hpp"
#include "enemyChar.hpp"

class bullet : public sf::CircleShape{
private:
	const sf::Vector2f & endPos;


public:
	bullet( const sf::Vector2f & beginPos, const sf::Vector2f & endPos, const int & size );

};

class shotHandler{
private:
	towerGroup & towers;
	enemyCharGroup & enemies;
	std::vector< bullet* > bullets;

public:
	shotHandler( towerGroup & towers, enemyCharGroup & enemies );

	void update();
};


#endif /*SHOTHANDLER_HPP*/