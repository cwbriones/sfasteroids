#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "Command.h"
#include "GameObject.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

#include <map>
#include <set>

class InputHandler {
public:
    enum Action {
        RotateLeft,
        RotateRight,
        MoveForward,
        NumActions
    };

    InputHandler();
    void handleInputEvent(const sf::Event& event, CommandQueue& queue);
    void handleRealtimeEvent(CommandQueue& queue);

    void assignKeyToAction(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key getAssignedKey(Action action) const;
private:
    void initializeBindings();
    void initializeActions();
    void initializeRealtimeSet();
    bool isRealtimeAction(Action action);
    
    // Bind keys to actions
    std::map<sf::Keyboard::Key, Action> key_bindings_;
    // Bind actions to commands
    std::map<Action, Command> action_bindings_;

    std::set<Action> realtime_actions_;
};

#endif /* INPUTHANDLER_H_ */
