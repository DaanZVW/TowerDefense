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

    // Variables for the tilemap
    sf::Vector2f position;
    sf::Vector2f size;

    // Standard texture for rest tiles
    const sf::Color &color;

    // Variable used for sizeing the grid
    sf::Vector2i gridSize;

    // Gridvector where all the tiles are stored
    std::vector<std::vector<tile*>> grid;

    // Change the tileindex to an texture and change the allowPlacement boolean
    bool changeTile( const sf::Vector2i &position, const sf::Color &color, const bool &allowPlacement );

    // Make all tiles
    void makeTilemap( const sf::Vector2i &gridSize );

public:

    // Default constructor
    // NOTE: position and size is for the tilemap itself
    tilemap( const sf::Vector2i &position, const sf::Vector2i &size, const sf::Vector2i &gridSize, const sf::Color &color );

    // Draw all the tiles
    void draw( sf::RenderWindow &window );

    // Change all the tiles within the nodes to given texture
    void makePath( const std::vector<sf::Vector2i> &nodes, const sf::Color &color );

    // Get the index of tile where point is in
    sf::Vector2i getTilePosition( sf::Vector2i tmpPosition );

    // Clear whole tile field and reset to default color
    void clearTilemap();

    // Get tile pointer from grid
    tile* getTileFromIndex( const sf::Vector2i &tileindex );

};

#endif /*TILEMAP_HPP*/ 

