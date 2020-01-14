// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class tile : public sf::RectangleShape{
private:

    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;

    bool placeable;

public:

    // Default constructor
    tile( const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color );
};

class tilemap {
private:

    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2i gridSize;
    const sf::Color &color;

    std::vector<std::vector<tile*>> grid;

public:

    // Default constructor
    // NOTE: position and size is for the tilemap itself
    tilemap( const sf::Vector2f &position, const sf::Vector2f &size, const sf::Vector2i &gridSize, const sf::Color &color );
    void draw( sf::RenderWindow &window );

};