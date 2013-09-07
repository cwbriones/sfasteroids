#include "EntityFactory.h"

#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"

EntityFactory::EntityFactory(){
    registerComponents();
}

Component::Ptr EntityFactory::createComponent(Components::ID id){
    auto found = component_factory_.find(id);
    assert(found != component_factory_.end());

    return found->second();
}

void EntityFactory::registerComponents(){
    registerComponent<ShipGraphicsComponent>(Components::kShipGraphics);
}

Entity::Ptr EntityFactory::createShip(){
    Entity::Ptr entity(new Entity());

    Component::Ptr graphics = createComponent(Components::kShipGraphics);
    entity->addComponent(Components::Graphics, std::move(graphics));

    return entity;
}
