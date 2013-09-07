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
    sf::Vector2u center = render_target_.getSize();

    auto ship = object_factory_.createShip();
    ship->setPosition(200.f, 200.f);
    game_objects_.push_back(std::move(ship));
}

void World::update(sf::Time delta_time){
    for (auto& object : game_objects_){
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
