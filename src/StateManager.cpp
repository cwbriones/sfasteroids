#include "StateManager.h"

StateManager::StateManager(State::Context context) 
    : context_(context) {}

void StateManager::popState(){
    state_stack_.pop_back();
}

void StateManager::pushState(States::ID id){
    State::Ptr new_state = createState(id);
    state_stack_.push_back(std::move(new_state));
}

void StateManager::clearStates(){
    while (!state_stack_.empty()){
        state_stack_.pop_back();
    }
}

void StateManager::clearToState(States::ID id){
    clearStates();
    pushState(id);
}

void StateManager::handleEvent(const sf::Event& event){
    for (auto iter = state_stack_.rbegin(); iter != state_stack_.rend(); ++iter){
        if (!(*iter)->handleEvent(event)){
            break;
        }
    }
    applyStateChanges();
}

void StateManager::update(sf::Time delta_time){
    for (auto iter = state_stack_.rbegin(); iter != state_stack_.rend(); ++iter){
        if (!(*iter)->update(delta_time)){
            break;
        }
    }
    applyStateChanges();
}

void StateManager::draw() const {
    for (auto iter = state_stack_.begin(); iter != state_stack_.end(); ++iter){
        (*iter)->draw();
    }
}

void StateManager::requestStateChange(Action action, States::ID new_id){
    StateChange change;

    change.action = action;
    change.id = new_id;

    pending_changes_.push(change);
}

void StateManager::applyStateChanges(){
    while (!pending_changes_.empty()){
        auto change = pending_changes_.front();

        switch (change.action){
            case Action::kClearAllStates:
                clearStates();
                break;
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
        pending_changes_.pop();
    }
}

bool StateManager::isEmpty(){
    return state_stack_.empty();
}

State::Ptr StateManager::createState(States::ID id){
    auto found = state_creator_.find(id);
    assert(found != state_creator_.end());

    return found->second();
}

inline const State* StateManager::getCurrentState(){
    return state_stack_.back().get();
}
