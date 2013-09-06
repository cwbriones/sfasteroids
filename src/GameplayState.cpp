#include "GameplayState.h"
#include "Utility.h"

GameplayState::GameplayState(StateManager& manager, Context context) : 
    State(manager, context), 
    text_(), 
    world_(*context.window)
{
    text_.setString("We'll be doing cool game stuff here.\nImagine it.");
    text_.setColor(sf::Color::White);
    text_.setFont(context.fonts->get(Fonts::kDefaultFont));
    Utility::centerOrigin(text_);

    sf::Window& window = *context.window;
    text_.setPosition(window.getSize().x/2u, window.getSize().y/2u);
}

bool GameplayState::update(sf::Time delta_time){
    world_.update(delta_time);
    input_handler_.handleRealtimeEvent(world_.getCommandQueue());

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

    CommandQueue& command_queue = world_.getCommandQueue();
    input_handler_.handleInputEvent(event, command_queue);

    return ALLOW_OTHER_UPDATES;
}

void GameplayState::draw() const {
    world_.draw();
}
