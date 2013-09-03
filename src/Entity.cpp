#include "Entity.h"

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
