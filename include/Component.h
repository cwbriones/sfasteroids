#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Identifier.h"
#include <SFML/System/Time.hpp>
#include <memory>

class Entity;

class Component {
public:
    typedef std::unique_ptr<Component> Ptr;

    virtual void update(Entity& entity, sf::Time delta_time){
        // Do nothing by default.
    };
    
    // Cross-component communication
    virtual void receiveMessage(Entity& entity, Components::ID id) = 0;
};

#endif /* COMPONENT_H_ */
