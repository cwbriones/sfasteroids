#ifndef TITLESTATE_H_
#define TITLESTATE_H_

#include "StateManager.h"
#include "State.h"

#include <SFML/Graphics/Text.hpp>

class TitleState : public State {
public:
    TitleState(StateManager& manager, Context context);
    virtual bool update(sf::Time delta_time) override;
    virtual bool handleEvent(const sf::Event& event) override;
    virtual void draw() const override;
private:
    sf::Time text_effect_time_;
    sf::Text text_;
    bool show_text_;
};

#endif /* TITLESTATE_H_ */
