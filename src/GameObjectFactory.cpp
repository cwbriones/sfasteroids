#include "GameObjectFactory.h"

#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"

GameObjectFactory::GameObjectFactory(){
    registerComponents();
}

Component::Ptr GameObjectFactory::createComponent(Components::ID id){
    auto found = component_factory_.find(id);
    assert(found != component_factory_.end());

    return found->second();
}

void GameObjectFactory::registerComponents(){
    registerComponent<ShipGraphicsComponent>(Components::kShipGraphics);
}

GameObject::Ptr GameObjectFactory::createShip(){
    GameObject::Ptr entity(new GameObject());

    Component::Ptr graphics = createComponent(Components::kShipGraphics);
    entity->addComponent(Components::Graphics, std::move(graphics));

    return entity;
}
