#ifndef CSCREEN_HPP
#define CSCREEN_HPP

#include <SFML/Graphics.hpp>

class cScreen{
    public:
    virtual int run(sf::RenderWindow &window) = 0;
};
#endif //CSCREEN_HPP