#include "InputHandler.h"
#include <cassert>
#include <iostream>

InputHandler::InputHandler(){
    initializeBindings();
    initializeActions();
    initializeRealtimeSet();
}

void InputHandler::initializeRealtimeSet(){
    realtime_actions_.insert(RotateLeft);
    realtime_actions_.insert(RotateRight);
    realtime_actions_.insert(MoveForward);
}

bool InputHandler::isRealtimeAction(Action action){
    return realtime_actions_.find(action) != realtime_actions_.end();
}

void InputHandler::handleInputEvent(const sf::Event& event, CommandQueue& queue){
    if (event.type == sf::Event::KeyPressed){
        auto found = key_bindings_.find(event.key.code);
        if (found != key_bindings_.end()){
            auto action = found->second;

            assert(action_bindings_.find(action) != action_bindings_.end());
            queue.push(action_bindings_[action]);
        }
    }
    return;
}

void InputHandler::handleRealtimeEvent(CommandQueue& queue){
    for (auto pair : key_bindings_){
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second)){
            queue.push(action_bindings_[pair.second]);
        }
    }
}

void InputHandler::assignKeyToAction(Action action, sf::Keyboard::Key key){
    key_bindings_[key] = action;
}

void InputHandler::initializeBindings(){
    // key_bindings_[MoveForward] = sf::Keyboard::Up;
    key_bindings_[sf::Keyboard::Left] = RotateLeft;
    key_bindings_[sf::Keyboard::Right] = RotateRight;
}

void InputHandler::initializeActions(){

    // Ship controls
    Command command;
    command.receiver_type = GameObjects::kShipObject;
    
    const float ROTATION_RATE = 2.f;
    // RotateLeft
    command.action = [=](GameObject& object, sf::Time delta_time){
        object.rotate(-ROTATION_RATE);
    };
    action_bindings_[RotateLeft] = command;

    // RotateRight
    command.action = [=](GameObject& object, sf::Time delta_time){
        object.rotate(ROTATION_RATE);
    };
    action_bindings_[RotateRight] = command;
}

sf::Keyboard::Key InputHandler::getAssignedKey(Action action) const {
    for (auto pair : key_bindings_){
        if (pair.second == action){
            return pair.first;
        }
    }

    return sf::Keyboard::Unknown;
}
