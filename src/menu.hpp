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


class menuTowerObject : public sf::RectangleShape{
private:

public:
	menuTowerObject(const sf::Vector2f & position, const sf::Vector2f & size );

};


class menu : public sf::RectangleShape{
private:
	sf::Vector2f position;
	sf::Vector2f size;
	std::vector<sf::Drawable*> drawables;

public:
	menu(const sf::Vector2f & position, const sf::Vector2f & size );

};

#endif /*MENU_HPP*/