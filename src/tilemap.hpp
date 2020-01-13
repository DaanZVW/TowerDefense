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

    sf::RectangleShape tile;

public:

    tile( const sf::Color &color, const sf::Vector2f &size );
    void draw( const sf::Vector2f &Position )

};

class tilemap {
private:

    std::vector<std::vector<sf::Drawable*>> grid;

public:

    tilemap( const sf::Color &color );
    void draw( sf::RenderWindow &window );

};