#ifndef TITLESTATE_H_
#define TITLESTATE_H_

#include "StateManager.h"
#include "State.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

class TitleState : public State {
public:
    TitleState(StateManager& manager, Context context);
    virtual bool update(sf::Time delta_time) override;
    virtual bool draw() const override;
    virtual bool handleEvent(const sf::Event& event) override;
};

#endif /* TITLESTATE_H_ */
