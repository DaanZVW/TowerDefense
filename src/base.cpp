#include "base.hpp"
#include "macro.hpp"
#include <iostream>

base::base(const sf::Vector2f& size, const sf::Vector2f& position, sf::Texture& texture, const unsigned int& health, gameState& state) :
	health(health),
	state(state),
	hpBar(health)
{
	LOGFUNCNAME();
	setSize(size);
	setPosition(position);
	setTexture(&texture);
	hpBar.setSize(sf::Vector2f(size.x, size.y * 0.1));
	hpBar.setPosition(position);
}
void base::decreaseHealth(const unsigned int& damage) {
	LOGFUNCNAME(<<damage);
	if (damage >= health) {
		state = gameState::GAMEOVER;
	}
	else {
		health -= damage;
		hpBar.setPercentage(health);
	}
}
void base::draw(sf::RenderWindow& window) {
	LOGFUNCNAME();
	window.draw(*this);
	hpBar.draw(window);
}