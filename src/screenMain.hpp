#include <iostream>
#include "cScreen.hpp"

#include <SFML/Graphics.hpp>

#include "button.hpp"

class screenMain : public cScreen{
    private:
    sf::Clock clock;
    public:
        screenMain(void);
        virtual int run(sf::RenderWindow &window);
};