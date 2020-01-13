// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>


class path {
private:

    std::vector<sf::Vector2i> nodes;

public:

    path( const std::vector<sf::Vector2i> &nodes );

};