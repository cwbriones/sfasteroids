#ifndef ENTITY_H_
#define ENTITY_H_

#include "SceneNode.h"

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Entity : public SceneNode {
    public:
        virtual void updateCurrent(sf::Time delta_time) override;
        
        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float vel_x, float vel_y);

        sf::Vector2f velocity();
    private:
        sf::Vector2f velocity_;
};

#endif /* ENTITY_H_ */
