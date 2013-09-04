#include "StateManager.h"

StateManager::StateManager(State::Context context) 
    : context_(context) {}

void StateManager::popState(){
    auto top = std::move(state_stack_.back());
    // Do something with the state about to be destroyed
    state_stack_.pop_back();
}

void StateManager::pushState(States::ID id){
    State::Ptr new_state = state_creator_[id]();
    state_stack_.push_back(std::move(new_state));
}

void StateManager::clearStates(){
    while (!state_stack_.empty()){
        auto top = std::move(state_stack_.back());
        // Do something with the state about to be destroyed

        state_stack_.pop_back();
    }
}

void StateManager::clearToState(States::ID id){
    clearStates();
    pushState(id);
}

void StateManager::update(sf::Time delta_time){
    state_stack_.back()->update(delta_time);
}

void StateManager::draw() const {
    state_stack_.back()->draw();
}

void StateManager::requestStateChange(Action action, States::ID new_id){
    StateChange chage;
    change.action = action;
    change.id = new_id;

    pending_changes_.push(change);
}

void StateManager::applyStateChanges(){
    while (!pending_changes_.empty()){
        auto change = pending_changes_.front();

        switch (change.action){
            case Action::kClearToState:
                clearToState(change.id);
                break;
            case Action::kPopState:
                popState();
                break;
            case Action::kPushState:
                pushState(change.id);
                break;
        }
    }
}

bool StateManager::isEmpty(){
    return state_stack_.empty();
}

State::Ptr StateManager::createState(States::ID id){
    return state_creator_[id]();
}

inline const State* StateManager::getCurrentState(){
    return state_stack_.back().get();
}
