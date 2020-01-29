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
#ifdef INCLUDE
	#include <jsoncpp/json/json.h>
#else
	#include <jsoncpp/json/json.h>
#endif

// Include Nessecery files
#include <SFML/Graphics.hpp>
#include "tower.hpp"

/// @brief Class to handle JSON files
class fileReader {
private:

    // Private Variables
    std::string filename;

    Json::Value fileInfo;

	std::map<std::string, sf::Texture> textures;
public:

    /// @brief Constructor for fileHandler.
    /// @param filename Location of the file that you want to be used with the filehandler
    fileReader( const std::string &filename );

    /// @brief Method to make nodes.
    /// @details This method makes the map nodes based on the json file. 
    /// @details Based on these nodes is the map generated.
    /// @return std::vector<sf::Vector2i>
    std::vector<sf::Vector2i> makeNodes();

    /// @brief Method to make tower.
    /// @details This method makes the towers based on the json file.
    /// @details These towers are used in the menu and in the game.
    /// @return std::vector< tower* >
    std::vector< tower* > makeTowers();

    /// @brief Method to get enemy info.
    /// @details This method gets the enemy info out of the json file.
    /// @details The info is used to generate enemy's in the waves.
    /// @return const Json::Value
	const Json::Value & getEnemyConfig();

    /// @brief Method to get waves.
    /// @details This method gets the waves out of the json file.
    /// @details These waves are pre-defined with how many enemy's there are in a wave.
    /// @return const Json::Value
	const Json::Value & getWaves();

    /// @brief Method to get base.
    /// @details This method gets the base config out of the json file.
    /// @details Based on this config is a base generated later in the program.
    /// @return const Json::Value
	const Json::Value & getBaseConfig();

    /// @brief Method to get textures.
    /// @details This method gets the textures that are needed ingame.
    /// @return std::map<std::string, sf::Texture>
	std::map<std::string, sf::Texture>  & getTextures();

    /// @brief Method to get grid size.
    /// @details This method gets the grid size out of the json file.
    /// @details This grid size is used to generate the map later in the game.
    /// @return sf::Vector2i
    sf::Vector2i getGridSize();

    /// @brief Method to get font.
    /// @details This method gets the font location out of the json file.
    /// @return sf::Font*
    sf::Font* getFont();

    /// @brief Method to get menutextures
    /// @details This method gets the textures that are used in the menu out of the json file.
    /// @param switchIndex Swaps the 2 indexes that are given, ignores when the same
    /// @return std::vector< sf::RectangleShape* >
    std::vector< sf::RectangleShape* > getMenuTextures( std::pair<int, int> switchIndex = {0,0} );

    /// @brief Method to get money.
    /// @details This method gets the money from the json file.
    /// @return uint32_t
    uint32_t getMoney();
};


/// @brief Class to write to a json file
/// @details With this class you can write information to a json file.
/// @details These file can be used in the game later on.
class fileWriter {
private:

    std::string filename;

public:

    /// @brief Constructor for filewriter
    /// @param filename The file you want to write to.
    fileWriter( const std::string &filename );

    /// @brief Method to create level.
    /// @details This method creates a level in a json file
    /// @details This file can be loaded in the game later on so you can make your own levels.
    /// @param name This is the level name.
    /// @param difficulty This the level difficulty
    /// @param nodes This are the nodes in the map.
    void makeLevelJson( const std::string &name, const std::string &difficulty, const std::vector<sf::Vector2i> &nodes );
};

#endif /*READFILE_HPP*/