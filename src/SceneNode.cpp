#include "SceneNode.h"

#include <cassert>

SceneNode::SceneNode(){}

void SceneNode::attachChild(Ptr child){
    child->parent_ = this;
    children_.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node){
    // Find the desired child
    auto found = std::find_if(children_.begin(), children_.end(),
            [&](Ptr& p) -> bool { return p.get() == &node; });
    assert(found != children_.end());

    // Remove it from the list
    Ptr result = std::move(*found);
    result->parent_ = nullptr;
    children_.erase(found);

    return result;
}

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;

    for (const SceneNode* node = this; node != nullptr; node = node->parent_){
        transform *= node->getTransform();
    }
    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return getWorldTransform() * sf::Vector2f();
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    drawCurrent(target, states);
    drawChildren(target, states);
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const Ptr& child : children_){
        child->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {

}

void SceneNode::update(sf::Time delta_time){
    updateCurrent(delta_time);
    updateChildren(delta_time);
}

void SceneNode::updateCurrent(sf::Time delta_time){}

void SceneNode::updateChildren(sf::Time delta_time){
    for (const Ptr& child : children_){
        child->update(delta_time);
    }
}

// void SceneNode::onCommand(const Command& command, sf::Time delta_time){
// }
