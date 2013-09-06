#include "EntityFactory.h"

EntityFactory::EntityFactory(){
    registerComponents();
}

Component::Ptr EntityFactory::createComponent(Components::ID id){
    auto found = component_factory_.find(id);
    assert(found != component_factory_.end());

    return found->second();
}

void EntityFactory::registerComponents(){
}
