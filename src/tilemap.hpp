// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#ifndef TILEMAP_HPP
#define TILEMAP_HPP

// Include std::libs
#include <vector>
#include <iostream>

// Include external libs
#include <SFML/Graphics.hpp>

class tile : public sf::RectangleShape{
private:

    bool allowplacement;

public:
    // Default constructor
    tile( const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color );

    // Getter and setter for AllowPlacement variable
    void setAllowPlacement( const bool &value );
    bool getAllowPlacement();

    void updateColor();
};

class tilemap {
private:

    sf::Vector2f position;
    sf::Vector2f size;
    const sf::Color &color;

    sf::Vector2i gridSize;

    std::vector<std::vector<tile*>> grid;
    
    bool changeTile( const sf::Vector2i &position, const sf::Color &color, const bool &allowPlacement );

public:

    // Default constructor
    // NOTE: position and size is for the tilemap itself
    tilemap( const sf::Vector2f &position, const sf::Vector2f &size, const int &tmpGridSize, const sf::Color &color );
    
    void draw( sf::RenderWindow &window );
    void makePath( const std::vector<sf::Vector2i> &nodes, const sf::Color &color );

    sf::Vector2i getTilePosition( sf::Vector2i tmpPosition );

};

#endif /*TILEMAP_HPP*/