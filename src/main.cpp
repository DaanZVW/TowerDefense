// ======================================
// = Author: Daan Zimmerman van Woesik  =
// = Insitute: HU                       =
// = Date: 12/12/2019                   =
// ======================================

#include "game.hpp"

int main() {
    game TowerDefense{ "../res/configfiles/config.json" };
    TowerDefense.run();
}
