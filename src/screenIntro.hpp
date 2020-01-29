#include <iostream>
#include "cScreen.hpp"

// #include <SFML/Graphics.hpp>

class screenIntro : public cScreen{
    private:
        sf::Sprite background;
        sf::Texture texture;
        sf::Text introText;
        sf::Font font;
        sf::Clock clock;

        void updateColor();
    public:
        screenIntro(void);
	    virtual int run(sf::RenderWindow &window);
};