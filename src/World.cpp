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
    sf::Vector2u center = render_target_.getSize();
    auto ship = object_factory_.createShip();
    ship->setPosition(center.x/2, center.y/2);

    game_objects_.push_back(std::move(ship));
    
    // Create the asteroids
}

void World::update(sf::Time delta_time){
    for (auto& object : game_objects_){
        object->update(delta_time);
    }
    processCommands(delta_time);
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
