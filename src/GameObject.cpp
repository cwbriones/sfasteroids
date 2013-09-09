#include "GameObject.h"
#include "Command.h"

#include "GraphicsComponent.h"
#include "Utility.h"

#include <cassert>

GameObject::GameObject(GameObjects::Type type) : type_(type) {}

void GameObject::update(sf::Time delta_time){
    // Update all of the components
    for (auto& component : components_){
        component.second->update(delta_time);
    }
    move();
    accelerate();
}

void GameObject::addComponent(Components::Type type, Component::Ptr component){
    component->setParent(this);
    auto inserted = components_.insert(std::make_pair(type, std::move(component)));

    assert(inserted.second);
}

bool GameObject::hasComponent(Components::Type type){
    return components_.find(type) != components_.end();
}

float GameObject::getRotationInRadians() const {
    return Utility::degreesToRadians(Transformable::getRotation());
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

void GameObject::move(){
    Transformable::move(velocity_.x, velocity_.y);
}

void GameObject::move(sf::Vector2f vel){
    Transformable::move(vel.x, vel.y);
}

void GameObject::accelerate(){
    velocity_ += acceleration_;
}

void GameObject::accelerate(sf::Vector2f acc){
    velocity_ += acc;
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

#include <iostream>

void GameObject::onCommand(Command& command, sf::Time delta_time){
    if (type_ == command.receiver_type){
        command.action(*this, delta_time);
    }
}
