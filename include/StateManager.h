#ifndef STATE_MANAGER_H_
#define STATE_MANAGER_H_

#include "State.h"

#include <SFML/System/NonCopyable.hpp>

#include <list>
#include <vector>

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

        void requestStateChange(StateChange type, States::ID new_id);
        void applyStateChanges();

        void pushState(States::ID id);
        void popState();
        void clearStates();

        void clearToState(States::ID id);
        bool isEmpty();

        void createState(States::ID id);

        template <typename StateType>
        void registerState(States::ID id);
    private:
        struct StateChange {
            Action action;
            State::ID id;
        };

        std::vector<StateChange> pendingChanges_;
        std::list<State::Ptr> stateStack_;
        std::map<States::ID, std::function<void(State::Ptr)>> stateCreator_;

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
