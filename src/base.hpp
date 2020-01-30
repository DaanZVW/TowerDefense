#ifndef BASE_HPP
#define BASE_HPP
#include <SFML/Graphics.hpp>
#include "healthBar.hpp"
#include <SFML/Audio.hpp>
/// @brief gameStates
/// @author Wilco Matthijssen
enum class  gameState { GAMEOVER, PLAYING, WON };


/// @brief Class for base that enemyChar is meant to destroy and towers are meant to defend
/// @author Wilco Matthijssen
class base : public sf::RectangleShape {
private:
	unsigned int health;
	healthBar hpBar;
	sf::Music damagemusic;
	gameState state{ gameState::PLAYING };
public:
	/// @brief	constructs a base
	///
	/// @param	size		size to set base
	/// @param	position	position to set base
	/// @param	texture		texture to set base
	/// @param	health		health to set base
	///
	base(const sf::Vector2f& size, const sf::Vector2f& position, sf::Texture& texture, const unsigned int& health);
	
	/// @brief	decreases health or changes state if damage >= health
	///
	/// @param	damage damage to decrease health with
	/// @return void
	///
	void decreaseHealth(const unsigned int& damage);


	/// @brief sets the internal state to gameState::WON
	///
	/// @return void
	///
	void win();
	
	bool isGameFinished();

	/// @brief	draws base to window
	///
	/// @param	window sf::RenderWindow to draw base onto
	/// @return void
	///
	void draw(sf::RenderWindow& window);
};

#endif // !BASE_HPP
