// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "fileHandeler.hpp"

sf::Color fileHandeler::isColor( const std::string &color ) {
    if ( color == "red" ) {
        return sf::Color::Red;
    } else if ( color == "blue" ){
        return sf::Color::Blue;
    } else if ( color == "green"){
        return sf::Color::Green;
    } else if ( color == "yellow") {
        return sf::Color::Yellow;
    } else if ( color == "cyan" ){
        return sf::Color::Cyan;
    } else if ( color == "magenta") {
        return sf::Color::Magenta;
    }
    return sf::Color::White;
}

// =================================================================================
// =================================================================================
// ===============================Constructor=======================================

fileHandeler::fileHandeler( const std::string &filename, sf::RenderWindow &window ):
    filename_read( filename ),
    window ( window )
{}

// =================================================================================

std::vector<drawable*> fileHandeler::readFile() {
    Json::Reader reader;
    Json::Value objects;

    std::ifstream fileReader(filename_read);

    reader.parse( fileReader, objects );
    std::vector<drawable*> objectVector = {};

    for (auto object : objects["Objects"]["Circle"]) {
        objectVector.push_back( 
            new ball{
                window, 
                sf::Vector2f{object["position_x"].asFloat(), object["position_y"].asFloat()},
                object["radius"].asFloat(),
                isColor(object["color"].asString())
            }
        );
    }

    for (auto object : objects["Objects"]["Rectangle"]) {
        objectVector.push_back( 
            new rectangle{
                window, 
                sf::Vector2f{object["position_x"].asFloat(), object["position_y"].asFloat()},
                sf::Vector2f{object["size_x"].asFloat(), object["size_y"].asFloat()},
                isColor(object["color"].asString())
            }
        );
    }

    for (auto object : objects["Objects"]["Picture"]) {
        objectVector.push_back( 
            new picture{
                window, 
                sf::Vector2f{object["position_x"].asFloat(), object["position_y"].asFloat()},
                sf::Vector2f{object["size_x"].asFloat(), object["size_y"].asFloat()},
                object["filename"].asString()
            }
        );
    }

    return objectVector;
}

// =================================================================================

void fileHandeler::writeFile( std::vector<drawable*> &drawableObjects, const std::string &filename ) {
    Json::Reader reader;
    Json::Value objects;

    std::ifstream fileReader(filename_read);
    reader.parse( fileReader, objects );

    std::array<std::string, 3> objectTypes = {"Circle", "Rectangle", "Picture"};
    int drawableIndex = 0;

    for (auto type : objectTypes) {
        for (auto &object : objects["Objects"][type]) {
            object["position_x"] = drawableObjects[drawableIndex]->getPosition().x;
            object["position_y"] = drawableObjects[drawableIndex]->getPosition().y;
            
            drawableIndex++;
        }
    }

    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "    ";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream(filename);
    writer -> write(objects, &outputFileStream);
}

void fileHandeler::writeFile( std::vector<drawable*> &drawableObjects ) {
    writeFile( drawableObjects, filename_read );
}