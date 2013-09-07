#ifndef PHYSICSCOMPONENT_H_
#define PHYSICSCOMPONENT_H_

class World;

class PhysicsComponent : public Component {
public:
    virtual void update(Entity& entity, World& world) = 0;
};

#endif /* PHYSICSCOMPONENT_H_ */
