#ifndef WORLD_H_
#define WORLD_H_

#include "Command.h"
#include "ResourceHolder.h"

#include "GameObject.h"
#include "GameObjectFactory.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

#include <vector>

class World : private sf::NonCopyable {
    public:
        explicit World(sf::RenderTarget& target);
        void update(sf::Time delta_time);
        void draw() const;
        void constrainObjects();

        CommandQueue& getCommandQueue();
    private:
        void loadTextures();
        void populate();
        void processCommands(sf::Time delta_time);
        
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

        GameObjectFactory object_factory_;
        std::vector<GameObject::Ptr> game_objects_;
};

#endif /* WORLD_H_ */
