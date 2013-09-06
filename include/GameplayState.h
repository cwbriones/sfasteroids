#ifndef GAMEPLAYSTATE_H_
#define GAMEPLAYSTATE_H_

#include "State.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include <SFML/System/Vector2.hpp>

class GameplayState : public State {
public:
    GameplayState(StateManager& manager, Context context);
    virtual bool update(sf::Time delta_time) override;
    virtual bool handleEvent(const sf::Event& event) override;
    virtual void draw() const override;
private:
    sf::Text text_;
    sf::CircleShape circle_;
    sf::Color circle_color_;
    sf::Vector2f circle_vel_;
};

#endif /* GAMEPLAYSTATE_H_ */
