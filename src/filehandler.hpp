// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

// Header define
#ifndef READFILE_HPP
#define READFILE_HPP

// Include std::libs
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Include External libs
#ifdef WILCO
#include <json/json.h>
#else
#include <jsoncpp/json/json.h>
#endif // WILCO
#include <SFML/Graphics.hpp>
#include "tower.hpp"

// Include Nessecery files
// something

class fileReader {
private:

    // Private Variables
    std::string filename;

    Json::Value fileInfo;

public:

    // Default read constructor
    fileReader( const std::string &filename );

    // Map information getter
    // Returns

    std::vector<sf::Vector2i> makeNodes();

    std::vector< tower* > makeTowers();

    sf::Vector2i getGridSize();

    sf::Font getFont();

    // // Reads the file given in constructor
    // // Returns a drawable pointer vector
    // std::vector<drawable*> readFile();

    // // Updates all the changed locations
    // // filename given with the function
    // void writeFile( std::vector<drawable*> &drawableObjects, const std::string &filename );

    // // Updates all the changed locations
    // // constructor filename is used
    // void writeFile( std::vector<drawable*> &drawableObjects );
};

class fileWriter {
private:

    // Private Variables
    std::string filename;

public:

    // Default read constructor
    fileWriter( const std::string &filename );

    void makeLevelJson( const std::string &name, const std::string &difficulty, const std::vector<sf::Vector2i> &nodes );
};

#endif /*READFILE_HPP*/