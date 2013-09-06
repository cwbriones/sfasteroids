#ifndef PAUSEDSTATE_H_
#define PAUSEDSTATE_H_

#include "State.h"
#include <SFML/Graphics/Text.hpp>

class PausedState : public State {
public:
    PausedState(StateManager& manager, Context context);
    virtual bool update(sf::Time delta_time) override;
    virtual bool handleEvent(const sf::Event& event) override;
    virtual void draw() const override;
private:
    sf::Text paused_text_;
    sf::Text instruction_text_;
};

#endif /* PAUSEDSTATE_H_ */
