#include "GameObject.h"

#include "InputComponent.h"
#include "GraphicsComponent.h"

#include <cassert>

GameObject::GameObject(){}

void GameObject::addComponent(Components::Type type, Component::Ptr component){
    component->setParent(this);
    auto inserted = components_.insert(std::make_pair(type, std::move(component)));

    assert(inserted.second);
}

bool GameObject::hasComponent(Components::Type type){
    return components_.find(type) != components_.end();
}

void GameObject::setVelocity(sf::Vector2f velocity){
    velocity_ = velocity;
}

void GameObject::setVelocity(float vel_x, float vel_y){
    velocity_.x = vel_x;
    velocity_.y = vel_y;
}

sf::Vector2f GameObject::velocity(){
    return velocity_;
}

void GameObject::onCommand(Command& command, sf::Time delta_time){
    
}
