#ifndef SCENENODE_H_
#define SCENENODE_H_

#include "Command.h"

#include <SFML/System.hpp>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <list>
#include <memory>

class SceneNode : public sf::Transformable, public sf::Drawable,
    private sf::NonCopyable {

    public:
        typedef std::unique_ptr<SceneNode> Ptr;

        SceneNode();

        void update(sf::Time delta_time);
        void attachChild(Ptr child);
        Ptr detachChild(const SceneNode& node);

        sf::Transform getWorldTransform() const;
        sf::Vector2f getWorldPosition() const;

        void onCommand(const Command& command, sf::Time delta_time);
    private:
        virtual void draw(sf::RenderTarget& target, 
                sf::RenderStates states) const final;
        virtual void drawCurrent(sf::RenderTarget& target, 
                sf::RenderStates states) const;
        void drawChildren(sf::RenderTarget& target, 
                sf::RenderStates states) const;

        virtual void updateCurrent(sf::Time delta_time);
        void updateChildren(sf::Time delta_time);

        SceneNode* parent_ = nullptr;
        std::list<Ptr> children_;
};

#endif /* SCENENODE_H_ */
