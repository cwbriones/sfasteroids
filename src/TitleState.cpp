#include "TitleState.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>

TitleState::TitleState(StateManager& manager, Context context) : State(manager, context) {}

bool TitleState::update(sf::Time delta_time){
    // return kAllowLowerUpdates
    return ALLOW_OTHER_UPDATES;
}

bool TitleState::handleEvent(const sf::Event& event){
    // return kSupressLowerUpdates;
    if (event.type == sf::Event::KeyPressed){
        requestClearToState(States::kGameplayState);
    }
    return SUPRESS_OTHER_UPDATES;
}

void TitleState::draw() const {
    sf::Text text("Press any key.", 
            getContext().fonts->get(Fonts::kDefaultFont), 40); 


    auto dim = getContext().window->getSize();
    text.setPosition(dim.x/2 - 10, dim.y/2);

    getContext().window->draw(text);
}
