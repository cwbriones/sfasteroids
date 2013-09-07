#include "World.h"

World::World(sf::RenderTarget& target) :
    render_target_(target),
    world_view_(target.getDefaultView()),
    textures_(),
    // scene_graph_(),
    // scene_layers_(),
    world_bounds_(0.f, 0.f, world_view_.getSize().x, world_view_.getSize().y),
    spawn_position_(),
    entity_factory_()
{
    loadTextures();
}

void World::loadTextures(){}

void World::populate(){}

void World::update(sf::Time delta_time){}

void World::draw() const {
    render_target_.setView(world_view_);
}

CommandQueue& World::getCommandQueue(){
    return command_queue_;
}
