#ifndef ENTITYFACTORY_H_
#define ENTITYFACTORY_H_

#include "Component.h"
#include "Entity.h"
#include "Identifier.h"

#include <functional>
#include <map>
#include <cassert>

class EntityFactory {
public:
    EntityFactory();

    Entity::Ptr createShip();
    // Entity::Ptr createAsteroid();
    // Entity::Ptr createAlien();

    template <class T>
    void registerComponent(Components::ID id);
private:
    void registerComponents();
    Component::Ptr createComponent(Components::ID id);
    std::map<Components::ID, std::function<Component::Ptr(void)>> component_factory_;
};

template <class ComponentType>
void EntityFactory::registerComponent(Components::ID id){
    auto found = component_factory_.find(id);
    assert(found == component_factory_.end());

    component_factory_[id] =
    [](){
        return Component::Ptr(new ComponentType());
    };
}

#endif /* ENTITYFACTORY_H_ */
