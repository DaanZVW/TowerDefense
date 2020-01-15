#include "game.hpp"

int main() {
    game TowerDefense{ "../res/configfiles/config.json" };
    TowerDefense.run();
}
