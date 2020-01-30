#include "base.hpp"
#include "macro.hpp"
#include <iostream>

base::base(const sf::Vector2f& size, const sf::Vector2f& position, sf::Texture& texture, const unsigned int& health) :
	health(health),
	hpBar(health)
{
	LOGFUNCNAME();
	setSize(size);
	setPosition(position);
	setTexture(&texture);
	hpBar.setSize(sf::Vector2f(size.x, size.y * 0.1));
	hpBar.setPosition(position);

	damagemusic.openFromFile("../res/sound/bhit_helmet-1.wav");
	damagemusic.setVolume( 15 );
}
void base::decreaseHealth(const unsigned int& damage) {
	LOGFUNCNAME(<<damage);
	if (damage >= health) {
		
		state = gameState::GAMEOVER;
	}
	else {
		damagemusic.stop();
		damagemusic.play();
		health -= damage;
		hpBar.setPercentage(health);
	}
}
void base::win() {
	LOGFUNCNAME();
	state = gameState::WON;
}

bool base::isGameFinished() {
	LOGFUNCNAME();
	if (state == gameState::GAMEOVER) {
		sf::Music music;
		music.openFromFile("../res/sound/smb_mariodie.wav");
		music.stop();
		music.play();
		sf::Clock T;
		while (T.getElapsedTime() < music.getDuration()) {}
			return true;
	}
	if (state == gameState::WON) {
		
		sf::Music music;
		music.openFromFile("../res/sound/smb_stage_clear.wav");
		music.stop();
		music.play();
		sf::Clock T;
		while (T.getElapsedTime() < music.getDuration() ) {}
		return true;
	}
	return false;
}
void base::draw(sf::RenderWindow& window) {
	LOGFUNCNAME();
	window.draw(*this);
	hpBar.draw(window);
}
