#include "screenPlay.hpp"

screenPlay::screenPlay(){

}

int screenPlay::run(sf::RenderWindow &window){
    bool running = true;
    sf::Event event;
    sf::RectangleShape rectangle;
    rectangle.setPosition(100, 100);
    rectangle.setSize(sf::Vector2f(50,50));
    rectangle.setFillColor(sf::Color::Blue);

    while(running){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                return (-1);
            }
            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Return:
                        return (1);

                    default:
                        break;
                }
            }
        }
        window.clear();
        window.draw(rectangle);
        window.display();
    }
    return -1;
}