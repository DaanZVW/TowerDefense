// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "path.hpp"

path::path( const std::vector<sf::Vector2i> &nodes ):
    nodes( nodes )
{
    for ( auto x : nodes ) {
        std::cout << x.x << " " << x.y << std::endl;
    }
}