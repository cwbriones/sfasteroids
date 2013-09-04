#include "State.h"

State::State(StateManager& manager, Context context) 
    : manager_(manager), context_(context) {}

State::Context::Context(
        sf::RenderWindow& window, 
        TextureHolder& textures, 
        FontHolder& fonts) 
    : window(&window), textures(&textures), fonts(&fonts) {}

void State::requestStatePush(States::ID id){
    manager_->requestStateChange(StateManager::kPushState,  id);
}

void State::requestStatePop(){
    manager_->requestStateChange(StateManager::kPopState, States::kNullState);
}

void State::requestClearToState(States::ID id){
    manager_->requestStateChange(StateManager::kClearToState, id);
}
