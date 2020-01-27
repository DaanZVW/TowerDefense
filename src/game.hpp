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
#include <SFML/Graphics.hpp>

// Include External files
#include "filehandler.hpp"
#include "tilemap.hpp"
#include "enemyChar.hpp"
#include "levelEditor.hpp"
#include "menu.hpp"
#include "mousecontrol.hpp"
#include "shothandler.hpp"
#include "base.hpp"
#include "healthBar.hpp"

#define TILEMAPSIZE 0.75

class game {
private:

    std::string configFilePath;

public:

    game( const std::string &configFilePath );

    void run();
};

#endif /*GAME_HPP*/