#ifndef ENTITY_H_
#define ENTITY_H_

#include "Identifier.h"
#include "Component.h"
#include "Command.h"

#include <map>
#include <queue>
#include <string>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Entity : public sf::Transformable {
    public:
        virtual void update(sf::Time delta_time);

        void addComponent(Components::ID id, Component* component);
        bool hasComponent(Components::ID id);
        const Component* getComponent(Components::ID id);

        void onCommand(Command& command, sf::Time delta_time);

        sf::Vector2f velocity();
        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float vel_x, float vel_y);
    private:
        sf::Vector2f velocity_;
        std::map<Components::ID, Component::Ptr> components_;
        // message queue for components
};

#endif /* ENTITY_H_ */
