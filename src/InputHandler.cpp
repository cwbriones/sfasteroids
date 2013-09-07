#include "InputHandler.h"

InputHandler::InputHandler(){
    initializeBindings();
    initializeActions();
}

bool InputHandler::isRealtimeAction(Action action){
    return false;
}

void InputHandler::handleInputEvent(const sf::Event& event, CommandQueue& queue){
    if (event.type == sf::Event::KeyPressed){
        auto found = key_bindings_.find(event.key.code);
        if (found == key_bindings_.end()){
            return;
        }
    }
}

void InputHandler::handleRealtimeEvent(CommandQueue& queue){

}

void InputHandler::assignKeyToAction(Action action, sf::Keyboard::Key key){
    key_bindings_[key] = action;
}

void InputHandler::initializeBindings(){
    key_bindings_[MoveForward] = sf::Keyboard::Up;
    key_bindings_[RotateLeft] = sf::Keyboard::Left;
    key_bindings_[RotateRight] = sf::Keyboard::Right;
}

void InputHandler::initializeActions(){
}

sf::Keyboard::Key InputHandler::getAssignedKey(Action action) const {
    for (auto pair : key_bindings_){
        if (pair.second == action){
            return pair.first;
        }
    }

    return sf::Keyboard::Unknown;
}
