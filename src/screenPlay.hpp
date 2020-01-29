#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

class screenPlay : public cScreen{
    private:
    public:
        screenPlay(void);
        virtual int run(sf::RenderWindow &window);
};