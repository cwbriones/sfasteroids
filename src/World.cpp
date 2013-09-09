#include "World.h"
#include "Utility.h"
#include "GraphicsComponent.h"

#include <algorithm>
#include <iostream>

// TODO:
// Figure out why the game is not updating based on simultaneous
// realtime input events.
// They are obviously being picked up and inserted into the queue
// as well as being processed
//
// (Holding Left and Right down shows that 2 commands are called each
// frame, one after the other.
//
// Yet for some reason, the ship only continues to rotate in the last
// direction pressed when you would expect it to stay still when both
// keys are held down (since it would be rotated one way and then
// immediately back the other way)
//
// FIXME:
// 
// EVEN MORE PECULIAR!!!
// Right held down and the left pressed makes it CONTINUE ROTATING TO THE RIGHT
// but FASTER
// Left held down and then right pressed will override the rotation to the left
// and make the ship rotate to the right, again at double speed.
//
// For some reason RotateRight is being called TWICE per frame when both keys are held.

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

// TODO: Make each method called once
// on a single iteration of the loop
// since currently we iterate over all objects
// about three times (update, removal, contraint)
// This may not help with commands (need to iterate over all)

void World::update(sf::Time delta_time){
    for (auto& object : game_objects_){
        object->update(delta_time);
    }
    processCommands(delta_time);
    constrainObjects();
    
    // Cleanup
    std::remove_if(game_objects_.begin(), game_objects_.end(),
        [](GameObject::Ptr& object) -> bool {
            return !object->isAlive();
        }
    );
}

void World::constrainObjects(){
    const float MAX_SHIP_SPEED = 5.0f;
    const auto bounds = render_target_.getSize();

    for (auto& object :game_objects_){
        // Wrap around positions
        auto position = object->getPosition();
        auto type = object->getType();

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
        if (type == GameObjects::kShipObject){
            sf::Vector2f velocity = object->velocity();

            Utility::clampVector(velocity, MAX_SHIP_SPEED);
            object->setVelocity(velocity);
        }
    }
}

void World::processCommands(sf::Time delta_time){
    while (!command_queue_.empty()){
        Command command = command_queue_.pop();

        for (auto& object : game_objects_){
            object->onCommand(command, delta_time);
        }
    }
}

void World::draw() const {
    render_target_.setView(world_view_);

    for (auto& object : game_objects_){
        const GraphicsComponent* graphics = 
            object->getComponent<GraphicsComponent>(Components::Graphics);

        if (graphics){
            render_target_.draw(*graphics);
        }
    }
}

CommandQueue& World::getCommandQueue(){
    return command_queue_;
}
