#ifndef MENU_HPP
#define MENU_HPP

#include "tower.hpp"
#include <vector>
#include <string>

class menuTextObject : public sf::Text{
private:
	std::string text;
	sf::Font font;

public:
	menuTextObject(const sf::Vector2f & position, const std::string & text);

};


class menu : public sf::RectangleShape{
private:
	sf::Vector2f position;
	sf::Vector2f size;
	const std::vector< tower* > & towers;

public:
	menu(const sf::Vector2f & position, const sf::Vector2f & size, const std::vector<tower*> & towers );

	void draw( sf::RenderWindow &window );
};

#endif /*MENU_HPP*/