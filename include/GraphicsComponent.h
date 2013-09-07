#ifndef GRAPHICSCOMPONENT_H_
#define GRAPHICSCOMPONENT_H_

#include "Component.h"

#include <SFML/Graphics/Drawable.hpp>

class GraphicsComponent : public Component, public sf::Drawable {};
#include <SFML/Graphics/VertexArray.hpp>

class ShipGraphicsComponent : public GraphicsComponent {
public:
    ShipGraphicsComponent();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void receiveMessage(GameObject& entity, Components::ID id){}
    virtual void update(sf::Time delta_time);
private:
    sf::VertexArray vertices_;
};

// class AsteroidGraphicsComponent : public GraphicsComponent {
// public:
//     virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
//     virtual void receiveMessage(GameObject& entity, Components::ID id);
// private:
//     sf::VertexArray vertices_;
// };

#endif /* GRAPHICSCOMPONENT_H_ */
