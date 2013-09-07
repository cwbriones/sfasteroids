#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Identifier.h"
#include <SFML/System/Time.hpp>
#include <memory>

class Entity;

class Component {
public:
    typedef std::unique_ptr<Component> Ptr;

    void setParent(Entity* parent){ 
        if (!parent_){ 
            parent_ =  parent; 
        } 
    }
    Entity* getParent(){ return parent_; }
    const Entity* getParent() const { return parent_; }
    virtual void update(sf::Time delta_time){}
    // Cross-component communication
    virtual void receiveMessage(Entity& entity, Components::ID id) = 0;
private:
    Entity* parent_ = nullptr;
};

#endif /* COMPONENT_H_ */
