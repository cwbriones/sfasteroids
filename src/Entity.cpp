#include "Entity.h"

#include "InputComponent.h"
#include "GraphicsComponent.h"

#include <cassert>

Entity::Entity(){}

void Entity::addComponent(Components::Type type, Component::Ptr component){
    component->setParent(this);
    auto inserted = components_.insert(std::make_pair(type, std::move(component)));

    assert(inserted.second);
}

bool Entity::hasComponent(Components::Type type){
    return components_.find(type) != components_.end();
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

void Entity::onCommand(Command& command, sf::Time delta_time){
    
}
