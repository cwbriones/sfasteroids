#include "GameObject.h"
#include "Command.h"

#include "InputComponent.h"
#include "GraphicsComponent.h"

#include <cassert>

GameObject::GameObject(GameObjects::Type type) : type_(type) {}

void GameObject::update(sf::Time delta_time){
    // Update all of the components
    for (auto& component : components_){
        component.second->update(delta_time);
    }
}

void GameObject::addComponent(Components::Type type, Component::Ptr component){
    component->setParent(this);
    auto inserted = components_.insert(std::make_pair(type, std::move(component)));

    assert(inserted.second);
}

bool GameObject::hasComponent(Components::Type type){
    return components_.find(type) != components_.end();
}

sf::Vector2f GameObject::velocity(){
    return velocity_;
}

void GameObject::setVelocity(sf::Vector2f velocity){
    velocity_ = velocity;
}

void GameObject::setVelocity(float vel_x, float vel_y){
    velocity_.x = vel_x;
    velocity_.y = vel_y;
}

sf::Vector2f GameObject::acceleration(){
    return acceleration_;
}

void GameObject::setAcceleration(sf::Vector2f acceleration){
    acceleration_ = acceleration;
}

void GameObject::setAcceleration(float acc_x, float acc_y){
    acceleration_.x = acc_x;
    acceleration_.y = acc_y;
}

void GameObject::onCommand(Command& command, sf::Time delta_time){
    if (type_ & command.receiver_type){
        command.action(*this, delta_time);
    }
}
