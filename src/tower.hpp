#ifndef TOWER_HPP
#define TOWER_HPP

#include "tilemap.hpp"



class tower : public sf::RectangleShape{
private:
	const std::string & name;
	int damage;
	int range;
	int firerate;
	sf::Color color;

public:

	tower( const std::string & name, const int & damage, const int & range, const int & firerate, const std::string & texture );

};

class towerGroup{
private:
	std::vector< tower* > towers;

public:
	towerGroup();


};





#endif /*TOWER_HPP*/