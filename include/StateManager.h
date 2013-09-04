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
            kClearToState
        };

        explicit StateManager(State::Context context);
        
        void update(sf::Time delta_time);
        void draw() const;
        void handleEvent(const sf::Event& event);

        void requestStateChange(Action action, States::ID new_id);
        void applyStateChanges();

        void pushState(States::ID id);
        void popState();
        void clearStates();

        void clearToState(States::ID id);
        bool isEmpty();

        State::Ptr createState(States::ID id);

        template <typename StateType>
        void registerState(States::ID id);

        const State* getCurrentState();
    private:
        struct StateChange {
            Action action;
            State::ID id;
        };

        std::queue<StateChange> pending_changes_;
        std::list<State::Ptr> state_stack_;
        std::map<States::ID, std::function<void(State::Ptr)>> state_creator_;

        State::Context context_;
};

template <typename StateType>
void StateManager::registerState<StateType>(States::ID id){
    stateCreator_[id] = 
    [this](){
        return State::Ptr(new StateType(*this, context_));
    };
}

#endif /* STATE_MANAGER_H_ */
