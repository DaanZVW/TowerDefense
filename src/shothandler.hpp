#ifndef SHOTHANDLER_HPP
#define SHOTHANDLER_HPP

#include "tower.hpp"
#include "enemyChar.hpp"

class bullet : public sf::CircleShape{
private:
	const sf::Vector2f & endPos;
	const int & tileSize;
	
	sf::Clock clock;
	sf::Vector2f direction;


public:
	bullet( const sf::Vector2f & beginPos, const sf::Vector2f & endPos, const int & tileSize );

	void updatePos();

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