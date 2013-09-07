#ifndef ENTITY_H_
#define ENTITY_H_

#include "Identifier.h"
#include "Component.h"
#include "Command.h"

#include <map>
#include <queue>
#include <memory>
#include <string>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Entity : public sf::Transformable {
    public:
        typedef std::unique_ptr<Entity> Ptr;
        Entity();

        void update(sf::Time delta_time);

        void addComponent(Components::Type type, Component::Ptr component);
        bool hasComponent(Components::Type type);

        template <class ComponentType>
        const ComponentType* getComponent(Components::Type type){
            auto pair = components_.find(type);
            if (pair != components_.end()){
                assert(dynamic_cast<const ComponentType*>(pair->second.get()));
                return static_cast<const ComponentType*>(pair->second.get());
            }
            return nullptr;
        }

        void onCommand(Command& command, sf::Time delta_time);

        sf::Vector2f velocity();
        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float vel_x, float vel_y);
    private:
        sf::Vector2f velocity_;
        std::map<Components::Type, Component::Ptr> components_;
        // message queue for components
};

#endif /* ENTITY_H_ */
