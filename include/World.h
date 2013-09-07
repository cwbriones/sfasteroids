#ifndef WORLD_H_
#define WORLD_H_

#include "Command.h"
#include "ResourceHolder.h"
#include "EntityFactory.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

#include <array>

class World : private sf::NonCopyable {
    public:
        explicit World(sf::RenderTarget& target);
        void update(sf::Time delta_time);
        void draw() const;

        CommandQueue& getCommandQueue();
    private:
        void loadTextures();
        void populate();
        
        enum Layer {
            kBackground,
            kAir,
            kLayerCount
        };

        sf::RenderTarget& render_target_;
        sf::View world_view_;
        
        TextureHolder textures_;
        // SceneNode scene_graph_;
        // std::array<SceneNode*, kLayerCount> scene_layers_;
        CommandQueue command_queue_;

        sf::FloatRect world_bounds_;
        sf::Vector2f spawn_position_;

        EntityFactory entity_factory_;
};

#endif /* WORLD_H_ */
