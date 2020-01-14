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
#include <jsoncpp/json/json.h>
#include <SFML/Graphics.hpp>

// Include Nessecery files
// something

class fileHandler {
private:

    // Private Variables
    std::string filename;

    Json::Value fileInfo;

public:

    // Constructor
    fileHandler( const std::string &filename );

    // Map information getter
    // Returns 

    // Reads the file given in constructor
    // Returns a drawable pointer vector
    std::vector<drawable*> readFile();

    // Updates all the changed locations
    // filename given with the function
    void writeFile( std::vector<drawable*> &drawableObjects, const std::string &filename );

    // Updates all the changed locations
    // constructor filename is used
    void writeFile( std::vector<drawable*> &drawableObjects );
};

#endif /*READFILE_HPP*/