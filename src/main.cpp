#include "game.hpp"
#include "screens.hpp"


enum class states{INTRO, GAME, TUTORIAL, QUIT};
int main() {
     game TowerDefense{ "../res/configfiles/config.json" };
     /*TowerDefense.run();*/

 //   //Applications variables
	//std::vector<cScreen*> screens;
	//int screen = 0;

	////Window creation
	//sf::RenderWindow window(sf::VideoMode { 
 //           sf::VideoMode::getDesktopMode().width, 
 //           sf::VideoMode::getDesktopMode().height
 //       },
 //       "Space Defense"
 //       ,sf::Style::Fullscreen);

	////Screens preparations
	//screenIntro s0;
	//screens.push_back(&s0);
	//screenMain s1;
	//screens.push_back(&s1);
 //   screenPlay s2;
 //   screens.push_back(&s2);

	////Main loop
	//while (screen >= 0)
	//{
	//	screen = screens[screen]->run(window);
	//}
	/*return EXIT_SUCCESS;
	*/

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
		case states::TUTORIAL: {
			std::cout << "do tutorial stuff" << std::endl;
			break;
		}
		}
	}

}
