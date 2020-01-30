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
	damagemusic.openFromFile("../res/sound/bhit_helmet-1.wav");
}
void base::decreaseHealth(const unsigned int& damage) {
	LOGFUNCNAME(<<damage);
	if (damage >= health) {
		damagemusic.stop();
		damagemusic.play();
		sf::Clock T;
 		while(T.getElapsedTime().asSeconds() < (damagemusic.getDuration().asSeconds()*2))
		state = gameState::GAMEOVER;
	}
	else {
		damagemusic.stop();
		damagemusic.play();
		health -= damage;
		hpBar.setPercentage(health);
	}
}
void base::draw(sf::RenderWindow& window) {
	LOGFUNCNAME();
	window.draw(*this);
	hpBar.draw(window);
}
