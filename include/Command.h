#ifndef COMMAND_H_
#define COMMAND_H_

#include "SceneNode.h"

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
struct Command {
    enum Type {
        kRealTime,
        kEventBased,
        kNumTypes,
    };
    std::function<void(SceneNode&, sf::Time)> action;
};

typedef std::queue<Command> CommandQueue;

#endif /* COMMAND_H_ */
