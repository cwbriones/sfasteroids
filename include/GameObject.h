#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Identifier.h"
#include "Component.h"

#include <map>
#include <queue>
#include <memory>
#include <string>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Command;

class GameObject : public sf::Transformable {
    public:
        typedef std::unique_ptr<GameObject> Ptr;
        GameObject(GameObjects::Type type);

        void update(sf::Time delta_time);

        void addComponent(Components::Type type, Component::Ptr component);
        bool hasComponent(Components::Type type);

        template <class ComponentType>
        const ComponentType* getComponent(Components::Type type){
            auto pair = components_.find(type);
            if (pair != components_.end()){
                assert(dynamic_cast<const ComponentType*>(pair->second.get()));
                return static_cast<const ComponentType*>(pair->second.get());
            }
            return nullptr;
        }

        void onCommand(Command& command, sf::Time delta_time);

        float getRotationInRadians() const;

        sf::Vector2f velocity();
        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float vel_x, float vel_y);

        sf::Vector2f acceleration();
        void setAcceleration(sf::Vector2f acceleration);
        void setAcceleration(float acc_x, float acc_y);

        void move();
        void move(sf::Vector2f vel);
        void accelerate();
        void accelerate(sf::Vector2f acc);

        bool isAlive(){ return alive_; }
        void kill(){ alive_ = false; }

        GameObjects::Type getType(){
            return type_;
        }
    private:
        sf::Vector2f velocity_;
        sf::Vector2f acceleration_;

        std::map<Components::Type, Component::Ptr> components_;
        GameObjects::Type type_ = GameObjects::kUnknownObject;
        
        bool alive_ = true;
        // message queue for components
};

#endif /* GAMEOBJECT_H */
