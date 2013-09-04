#ifndef COMMAND_H_
#define COMMAND_H_

#include <functional>
#include <SFML/System/Time.hpp>

struct Command {
    std::function<void(SceneNode&, sf::Time)> action;
};

#endif /* COMMAND_H_ */
