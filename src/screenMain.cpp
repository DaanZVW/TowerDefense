#include "screenMain.hpp"

screenMain::screenMain(){

}

int screenMain::run(sf::RenderWindow &window){
    bool running = true;
    sf::Event event;

    while(running){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                return (-1);
            }
            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Escape:
                        return (-1);
                    default:
                        break;
                }
            }
        }
        if(clock.getElapsedTime().asSeconds() > 5){
            clock.restart();
            return (0);
        }
        window.clear();
        window.display();
    }
    return -1;
}





// Play 
// Create level 
// Exit