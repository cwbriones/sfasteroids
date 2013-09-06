#include "TitleState.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>

TitleState::TitleState(StateManager& manager, Context context) :
State(manager, context), show_text_(true)
{
    text_.setString("Press any key.");
    text_.setColor(sf::Color::White);
    text_.setFont(context.fonts->get(Fonts::kDefaultFont));

    auto dim = context.window->getSize();
    text_.setPosition(dim.x/2 - 10, dim.y/2);
}

bool TitleState::update(sf::Time delta_time){
    const sf::Time update_time = sf::seconds(0.5f);

    if ((text_effect_time_ += delta_time) > update_time){
        text_effect_time_ = sf::Time::Zero;
        show_text_ = !show_text_;
    } 
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
    if (show_text_){
        getContext().window->draw(text_);
    }
}
