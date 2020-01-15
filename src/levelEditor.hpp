// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#ifndef LEVELEDITOR_HPP
#define LEVELEDITOR_HPP

// Include std::libs
#include <vector>
#include <iostream>

// Include external libs
#include <SFML/Graphics.hpp>

// Include external files
#include "tilemap.hpp"
#include "filehandler.hpp"

class levelEditor {
private:

    tilemap &map;
    std::vector<sf::Vector2i> nodes;

    void writeTileMap();

public:

    levelEditor( tilemap &map );
    void addNode( const sf::Vector2i &position );
    void popNode();

    void makeLevel( const std::string &path, const std::string &name, const std::string &difficulty );
};

#endif /*LEVELEDITOR_HPP*/