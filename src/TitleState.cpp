#include "TitleState.h"

TitleState::TitleState(StateManager& manager, Context context) : State(manager, context) {}

bool TitleState::update(sf::Time delta_time){
    // return kAllowLowerUpdates
    return ALLOW_OTHER_UPDATES;
}

bool TitleState::handleEvent(const sf::Event& event){
    // return kSupressLowerUpdates;
    return SUPRESS_OTHER_UPDATES;
}

void TitleState::draw() const {}
