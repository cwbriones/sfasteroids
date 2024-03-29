#ifndef COMMAND_H_
#define COMMAND_H_

#include "Identifier.h"

#include <SFML/System/Time.hpp>

#include <functional>
#include <queue>

// Possibility:
// Since commands can be used for other events
// such as AI, should the input type really be in the Command
// class as such?

/**
 * Struct representing a command issued to an object in the 
 * Scene. Can be real time or event-based (a distinction
 * of whether the command is issued upon an input event
 * or DURING an input event)
 */
class GameObject;

struct Command {

    enum Type {
        kRealTime,
        kEventBased,
        kNumTypes,
    };

    GameObjects::Type receiver_type;
    std::function<void(GameObject&, sf::Time)> action;

};

class CommandQueue {
public:
    void push(Command& command){
        queue_.push(command);
    }

    Command pop(){
        Command c = queue_.front();
        queue_.pop();
        return c;
    }

    bool empty(){
        return queue_.empty();
    }
private:
    std::queue<Command> queue_;
};

#endif /* COMMAND_H_ */
