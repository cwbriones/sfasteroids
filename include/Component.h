#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Identifier.h"
#include <SFML/System/Time.hpp>
#include <memory>

class GameObject;

class Component {
public:
    typedef std::unique_ptr<Component> Ptr;

    void setParent(GameObject* parent){ 
        if (!parent_){ 
            parent_ =  parent; 
        } 
    }
    GameObject* getParent(){ return parent_; }
    const GameObject* getParent() const { return parent_; }
    virtual void update(sf::Time delta_time){}
    // Cross-component communication
    virtual void receiveMessage(GameObject& entity, Components::ID id) = 0;
private:
    GameObject* parent_ = nullptr;
};

#endif /* COMPONENT_H_ */
