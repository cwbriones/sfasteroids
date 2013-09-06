#ifndef GAMEPLAYSTATE_H_
#define GAMEPLAYSTATE_H_

#include "State.h"
#include <SFML/Graphics/Text.hpp>

class GameplayState : public State {
public:
    GameplayState(StateManager& manager, Context context);
    virtual bool update(sf::Time delta_time) override;
    virtual bool handleEvent(const sf::Event& event) override;
    virtual void draw() const override;
private:
    sf::Time text_effect_time_;
    sf::Text text_;
    bool show_text_;
};

#endif /* GAMEPLAYSTATE_H_ */
