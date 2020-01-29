#include "screenIntro.hpp"

screenIntro::screenIntro(void){
    texture.loadFromFile("../res/images/intro.jpg");
    background.setScale(float(sf::VideoMode::getDesktopMode().width) / float(texture.getSize().x), float(sf::VideoMode::getDesktopMode().height) / float(texture.getSize().y));
    background.setTexture(texture);
    if(!font.loadFromFile("../res/fonts/joystick.ttf")){
        std::cerr<<"cant load font\n";
    }else{
    introText.setFont(font);
    introText.setString("Press space to continue...");
    introText.setFillColor(sf::Color(255, 255, 255, 200));
    introText.setCharacterSize(20);
    introText.setCharacterSize(20 * ((sf::VideoMode::getDesktopMode().width * 0.60) / introText.getLocalBounds().width ));
    introText.setStyle(sf::Text::Regular);
    introText.setOrigin(introText.getLocalBounds().width / 2, introText.getLocalBounds().height / 2);
    introText.setPosition((float(sf::VideoMode::getDesktopMode().width / 2.0)), float(sf::VideoMode::getDesktopMode().height * (4.0/5.0)));
    }
}

void screenIntro::updateColor(){
        if(clock.getElapsedTime().asSeconds() > 1){
        clock.restart();
        if(introText.getFillColor() == sf::Color(255, 255, 255, 200)){
            introText.setFillColor(sf::Color(160,160,160, 200));
        }else{
            introText.setFillColor(sf::Color(255, 255, 255, 200));
        }
    }
}


int screenIntro::run(sf::RenderWindow &window){
    bool running = true;
    sf::Event event;

    while(running){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                return (-1);
            }
            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Space:
                        return (1);
                    case sf::Keyboard::Escape:
                        return (-1);
                    default:
                        break;
                }
            }
        }
        updateColor();
        window.clear();
        window.draw(background);
        window.draw(introText);
        window.display();
    }
    return -1;
}


