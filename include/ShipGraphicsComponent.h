#ifndef SHIPGRAPHICSCOMPONENT_H_
#define SHIPGRAPHICSCOMPONENT_H_

#include <SFML/Graphics/VertexArray.hpp>

class ShipGraphicsComponent : public GraphicsComponent {
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void receiveMessage(Entity& entity, Components::ID id);
    sf::Vector2f getCenter(){ return center_; }
private:
    sf::VertexArray vertices_;
    const sf::Vector2f center_;
};

#endif /* SHIPGRAPHICSCOMPONENT_H_ */
