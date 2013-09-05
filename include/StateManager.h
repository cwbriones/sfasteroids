#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_

#include "State.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <list>
#include <queue>

class StateManager : private sf::NonCopyable {
    public:
        enum Action {
            kPushState,
            kPopState,
            kClearToState,
            kClearAllStates
        };

        explicit StateManager(State::Context context);
        const State* getCurrentState();
        
        void update(sf::Time delta_time);
        void draw() const;
        void handleEvent(const sf::Event& event);

        void requestStateChange(Action action, States::ID new_id);
        bool isEmpty();

        template <typename StateType>
        void registerState(States::ID id);
    private:
        void applyStateChanges();

        void popState();
        void pushState(States::ID id);

        void clearStates();
        void clearToState(States::ID id);

        State::Ptr createState(States::ID id);

        struct StateChange {
            Action action;
            State::ID id;
        };

        std::list<State::Ptr> state_stack_;
        std::queue<StateChange> pending_changes_;

        // Maps state IDs to their constructors
        std::map<States::ID, std::function<void(State::Ptr)>> state_creator_;

        State::Context context_;
};

/**
 * Assigns a state constructor to a specified state ID
 */
template <typename StateType>
void StateManager::registerState<StateType>(States::ID id){
    stateCreator_[id] = 
    [this](){
        return State::Ptr(new StateType(*this, context_));
    };
}

#endif /* STATE_MANAGER_H_ */
