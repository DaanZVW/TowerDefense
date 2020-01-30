#include "game.hpp"

// Make a switchcase for states
enum class states{INTRO, GAME};
int main() {
	
	// Make an TowerDefense object
     	game TowerDefense{ "../res/configfiles/config.json" };
	
	// Start the background music, this will play the whole game
	sf::Music backGroundMusic;
	backGroundMusic.openFromFile( "../res/sound/background.wav" );
	backGroundMusic.setLoop( true );
	backGroundMusic.play();
	
	// States switchcase
	states state = states::INTRO;
	while (TowerDefense.window.isOpen()) {
		switch (state) {
		case states::INTRO: {
			TowerDefense.intro();
			state = states::GAME;
			break;
		}
		case states::GAME: {
			TowerDefense.run();
			state = states::INTRO;
			break;
		}
		default:
			break;
		}
	}

}
