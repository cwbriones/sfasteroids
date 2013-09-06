#include "Entity.h"

void addComponent(Components::ID id, Component* component){
    Component::Ptr ptr(component);

    components_[id] = std::move(ptr);
}

bool hasComponent(Components::ID id){
    return components_.find(id) != components_.end();
}

const Component* getComponent(Components::ID id){
    auto item = components_.find(id);
    if (item != components_.end()) {
        return nullptr;
    }

    Component* component = item.second();

    switch (id){
        case Components::kGraphics:
            break;
        case Components::kPhysics:
            break;
        case Components::kInput:
            break;
        default:
            return component;
    }
}

void Entity::updateCurrent(sf::Time delta_time){
    // move(velocity_ * delta_time.asSeconds());
}

void Entity::setVelocity(sf::Vector2f velocity){
    velocity_ = velocity;
}

void Entity::setVelocity(float vel_x, float vel_y){
    velocity_.x = vel_x;
    velocity_.y = vel_y;
}

sf::Vector2f Entity::velocity(){
    return velocity_;
}
