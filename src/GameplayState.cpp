#include "GameplayState.h"
#include "Utility.h"

GameplayState::GameplayState(StateManager& manager, Context context) : 
    State(manager, context), text_(), show_text_(false)
{
    text_.setString("We'll be doing cool game stuff here.\nImagine it.");
    text_.setColor(sf::Color::White);
    text_.setFont(context.fonts->get(Fonts::kDefaultFont));
    centerOrigin(text_);

    sf::Window& window = *context.window;
    text_.setPosition(window.getSize().x/2u, window.getSize().y/2u);
}

bool GameplayState::update(sf::Time delta_time){
    const sf::Time update_time = sf::seconds(0.5f);

    if ((text_effect_time_ += delta_time) > update_time){
        text_effect_time_ = sf::Time::Zero;
        show_text_ = !show_text_;
    } 

    return ALLOW_OTHER_UPDATES;
}

bool GameplayState::handleEvent(const sf::Event& event){
    if (event.type == sf::Event::KeyPressed){
        if (event.key.code == sf::Keyboard::P){
            requestStatePush(States::kPausedState);
        }
        if (event.key.code == sf::Keyboard::BackSpace){
            requestClearToState(States::kTitleState);
        }
    }

    return ALLOW_OTHER_UPDATES;
}

void GameplayState::draw() const {
    if (show_text_){
        getContext().window->draw(text_);
    }
}
