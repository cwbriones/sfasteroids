#ifndef WORLD_H_
#define WORLD_H_

#include "ResourceHolder.h"
#include "SceneNode.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/FloatRect.hpp>

#include <array>

class World : private sf::NonCopyable {
    public:
        explicit World(sf::RenderWindow& window);
        void update(sf::Time delta_time);
        void draw();
    private:
        void loadTextures();
        void buildScene();
        
        enum Layer {
            kBackground,
            kAir,
            kLayerCount
        };

        sf::RenderWindow& window_;
        sf::View world_view_;
        
        TextureHolder textures_;
        SceneNode scene_graph_;
        std::array<SceneNode*, kLayerCount> scene_layers_;

        sf::FloatRect world_bounds_;
        sf::Vector2f spawn_position_;
        float scroll_speed_;
};

#endif /* WORLD_H_ */
