#ifndef GAME_H_
#define GAME_H_

#include "RenderingMonitor.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Game {
    public:
        Game();
        int run();
    private:
        void processEvents();
        void update(sf::Time delta_time);
        void render();

        sf::RenderWindow window_;
        RenderingMonitor rendering_monitor_;
};

#endif /* GAME_H_ */
