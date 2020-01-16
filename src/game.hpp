// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#ifndef GAME_HPP
#define GAME_HPP

// Include std::libs
#include <iostream>
#include <vector>

// Include External libs
#include <json/json.h>
#include <SFML/Graphics.hpp>

// Include External hpp's
#include "filehandler.hpp"
#include "tilemap.hpp"
#include "enemyChar.hpp"
#include "levelEditor.hpp"
#include "menu.hpp"

#define TILEMAPSIZE 0.75

class game {
private:

    std::string configFilePath;

public:

    game( const std::string &configFilePath );

    void run();
};

#endif /*GAME_HPP*/