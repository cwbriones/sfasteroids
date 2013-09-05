#ifndef GAME_H_
#define GAME_H_

#include "StateManager.h"
#include "RenderingMonitor.h"
#include "ResourceHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Game {
    public:
        Game();
        int run();
    private:
        void registerStates();
        void processEvents();
        void update(sf::Time delta_time);
        void render();

        // These will define the context
        sf::RenderWindow window_;
        TextureHolder textures_;
        FontHolder fonts_;

        // Managers and monitors
        RenderingMonitor rendering_monitor_;
        StateManager state_manager_;
};

#endif /* GAME_H_ */
