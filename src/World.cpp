#include "World.h"
#include "Utility.h"
#include "GraphicsComponent.h"

#include <iostream>

World::World(sf::RenderTarget& target) :
    render_target_(target),
    world_view_(target.getDefaultView()),
    textures_(),
    // scene_graph_(),
    // scene_layers_(),
    world_bounds_(0.f, 0.f, world_view_.getSize().x, world_view_.getSize().y),
    spawn_position_(),
    object_factory_()
{
    loadTextures();
    populate();
}

void World::loadTextures(){}

void World::populate(){
    // Create the ship
    GameObject::Ptr ship = object_factory_.createShip();
    sf::Vector2u center = render_target_.getSize();
    ship->setPosition(center.x/2, center.y/2);

    game_objects_.push_back(std::move(ship));
    // Create the asteroids
}

void World::update(sf::Time delta_time){
    for (auto& object : game_objects_){
        object->update(delta_time);
    }
    processCommands(delta_time);
    constrainObjects();
}

void World::constrainObjects(){
    const float MAX_SHIP_SPEED = 5.0f;
    const auto bounds = render_target_.getSize();

    for (auto& object :game_objects_){
        // Wrap around positions
        auto position = object->getPosition();
        if (position.x > bounds.x){
            object->setPosition(0, position.y);
        }
        else if (position.x < 0){
            object->setPosition(bounds.x, position.y);
        }
        if (position.y > bounds.y){
            object->setPosition(position.x, 0);
        }
        else if (position.y < 0){
            object->setPosition(position.x, bounds.y);
        }

        // Constrain to max speeds
        if (object->getType() == GameObjects::kShipObject){
            // sf::Vector2f velocity = object->velocity();
            // if (Utility::length(velocity) > MAX_SHIP_SPEED){
            //     Utility::setLength(velocity, MAX_SHIP_SPEED);
            //     object->setVelocity(velocity);
            // }
        }
    }
}

void World::processCommands(sf::Time delta_time){
    while (!command_queue_.empty()){
        Command& command = command_queue_.back();

        for (auto& object : game_objects_){
            object->onCommand(command, delta_time);
        }

        command_queue_.pop();
    }
}

void World::draw() const {
    render_target_.setView(world_view_);

    for (auto& object : game_objects_){
        auto graphics = 
            object->getComponent<GraphicsComponent>(Components::Graphics);
        if (object){
            render_target_.draw(*graphics);
        }
    }
}

CommandQueue& World::getCommandQueue(){
    return command_queue_;
}
