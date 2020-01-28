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

/// @brief Class for a tile in the tilemap
/// @author Daan Zimmerman van Woesik, Bas van der Geer, Nic Jenneboer
class tile : public sf::RectangleShape{
private:

    bool allowplacement;
    
public:
    
    /// @brief Construct an tile with given parameters
	///
	/// @param position	Used for placing the tile on given pixel location
	/// @param size     Used for giving the tile a size
	/// @param color    Given texture will be used for itself
    /// 
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

    // Variable used for sizeing the grid
    sf::Vector2i gridSize;

    // Standard texture for rest tiles
    const sf::Color &color;

    // X and Y offsets
    float XOffset;
    float YOffset;

    float tileSize;

    // Gridvector where all the tiles are stored
    std::vector<std::vector<tile*>> grid;

    // Grid background
    const sf::Texture * background_image;

    // Change the tileindex to an texture and change the allowPlacement boolean
    bool changeTile( const sf::Vector2i &position, const sf::Color &color, const bool &allowPlacement );

    // Make all tiles
    void makeTilemap( const sf::Vector2i &gridSize );

public:

    // Default constructor
    // NOTE: position and size is for the tilemap itself
    tilemap( const sf::Vector2i &position, const sf::Vector2i &size, const sf::Vector2i &gridSize, const sf::Color &color, const sf::Texture * background_image );

    // Draw all the tiles
    void draw( sf::RenderWindow &window );

    // Change all the tiles within the nodes to given texture
    void makePath( const std::vector<sf::Vector2i> &nodes, const sf::Color &color );

    // Get the index of tile where point is in
    sf::Vector2i getTilePosition( sf::Vector2i tmpPosition );

    sf::Vector2f getPixelPosition( sf::Vector2i tmpPosition );


    // Clear whole tile field and reset to default color
    void clearTilemap();

    // Get tile pointer from grid
    tile* getTileFromIndex( sf::Vector2i &tileindex );

    // Get tile size
    float getTileSize();
    
    // Get map position
    sf::Vector2f getMapPosition();

    // Get map size
    sf::Vector2f getMapSize();

    void makeRandomTiles(const int & amount, const sf::Texture * image);

};

#endif /*TILEMAP_HPP*/ 

