#include "GraphicsComponent.h"
#include "GameObject.h"

#include <SFML/Graphics/RenderTarget.hpp>

#include <cassert>

ShipGraphicsComponent::ShipGraphicsComponent() {
    const int NUM_VERTICES = 4;
    const float SCALE = 2.5;

    vertices_ = sf::VertexArray(sf::LinesStrip, NUM_VERTICES + 1);

    const int xCoords[NUM_VERTICES] = {0, 6, 12, 6};
    const int yCoords[NUM_VERTICES] = {15, 10, 15, 0};

    const sf::Vector2f center_(SCALE * 6.0f, SCALE * 7.5f);

    for(int i = 0; i < NUM_VERTICES; i++){
        vertices_[i].position = sf::Vector2f(SCALE * xCoords[i] - center_.x, SCALE * yCoords[i] - center_.y);
    }
    // Draw line to fully enclose shape
    vertices_[NUM_VERTICES] = sf::Vector2f(SCALE * xCoords[0] - center_.x, SCALE * yCoords[0] - center_.y);
}

void ShipGraphicsComponent::update(sf::Time delta_time){

}

void ShipGraphicsComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    assert(getParent());
    target.draw(vertices_, getParent()->getTransform());
}
