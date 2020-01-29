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
/// @author Daan Zimmerman van Woesik, Bas van der Geer & Nic Jenneboer
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
    
    /// @brief Set the allowplacement variable
    /// @details This variable is used for placing purposes
    /// @details When this is true you are able to place a tower on this tile, false otherway round
    ///
    /// @param value Set allowplacement to value
    /// @return void
    ///
    void setAllowPlacement( const bool &value );

    /// @brief Get the allowplacement variable
    /// @details This variable is used for placing purposes
    /// @details When this is true you are able to place a tower on this tile, false otherway round
    ///
    /// @return The allowPlacement boolean
    ///
    bool getAllowPlacement();
};

/// @brief Class for the tilemap
/// @author Daan Zimmerman van Woesik, Bas van der Geer & Nic Jenneboer
class tilemap {
private:

    sf::Vector2f position;
    sf::Vector2f size;

    sf::Vector2i gridSize;

    const sf::Color &color;

    float XOffset;
    float YOffset;

    float tileSize;

    std::vector<std::vector<tile*>> grid;

    const sf::Texture * background_image;


    /// @brief Change variables of a tile on the position vector2i
    /// 
    /// @param position The x and y index of the tile
    /// @param color    The color where the tile is changed to
    /// @param allowPlacement Change the allowplacement variable to this boolean
    /// @return returns if succesfull
    ///
    bool changeTile( const sf::Vector2i &position, const sf::Color &color, const bool &allowPlacement );

    /// @brief This function sets all the correct positions of the tiles and puts them in grid
    ///
    /// @param gridSize Max gridSize that the grid may use
    /// @return void
    ///
    void makeTilemap( const sf::Vector2i &gridSize );

public:

    /// @brief Constructor for the tilemap
    ///
    /// @param gridSize Max gridSize that the grid may use
    /// @param position Position which is used for the tilemap
    /// @param size     Size which is used for the tilemap
    /// @param gridSize Gridsize which the tilemap can use as a maximum
    /// @param color    Standard color which is used for the tiles
    /// @param background_image Standard background picture which is used for the tilemap
    ///
    tilemap( 
        const sf::Vector2i &position, 
        const sf::Vector2i &size, 
        const sf::Vector2i &gridSize, 
        const sf::Color &color, 
        const sf::Texture * background_image 
    );

    /// @brief Draw all the excisting objects of the tilemap
    /// 
    /// @param window RenderWindow where all the objects are gonna be drawn on
    /// @return void
    ///
    void draw( sf::RenderWindow &window );

    /// @brief Change all the tiles within the nodes to a given texture
    /// 
    /// @param nodes All the nodes that are given and make a path between them
    /// @param color Set all the path tiles the given color
    /// @return void
    ///
    void makePath( const std::vector<sf::Vector2i> &nodes, const sf::Color &color );

    /// @brief Give back Position of the tile which point is pointing at
    /// 
    /// @param tmpPosition An pixel position on the map
    /// @return Return a position of the tile where the tmpPosition is at
    ///
    sf::Vector2f getPixelPosition( sf::Vector2i tmpPosition );


    // Clear whole tile field and reset to default color
    /// @brief Clear all the tiles and give them the color from tilemap
    /// 
    /// @return void
    ///
    void clearTilemap();

    /// @brief Give back an index on which the point is at
    /// 
    /// @param tmpPosition An pixel position on the map
    /// @return Return a index position where {-1, -1} is outside the tilemap
    ///
    sf::Vector2i getTilePosition( sf::Vector2i tmpPosition );

    /// @brief Give back the tile where the index vector is pointing at
    /// @details Mostly paired up with getTilePosition function, if outside vector will be undefined behavior
    ///
    /// @param tileIndex Tile index where a tile is in the tilemap
    /// @return Returns the tile pointer
    ///
    tile* getTileFromIndex( sf::Vector2i &tileindex );

    /// @brief Give back the tilesize which is used for the tiles
    ///
    /// @return Return the tilesize
    ///
    float getTileSize();
    
    // Get map position
    /// @brief Gives back the tilemap position
    ///
    /// @return Returns the vector2f with the position
    ///
    sf::Vector2f getMapPosition();

    // Get map size
    /// @brief Give back the tilemap size
    ///
    /// @return Return the vector2f with the size
    ///
    sf::Vector2f getMapSize();

    /// @brief Puts random obstacles on the tilemap
    ///
    /// @param amount Amount of obstacles are gonna be put on the tilemap
    /// @param image Picture which is used for the obstacles
    /// @return void
    ///
    void makeRandomTiles(const int & amount, const sf::Texture * image);

};

#endif /*TILEMAP_HPP*/ 

