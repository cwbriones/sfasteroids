#ifndef INPUTCOMPONENT_H_
#define INPUTCOMPONENT_H_

#include <SFML/System/Time.hpp>

class InputComponent : public Component {
public:
    virtual void onCommand(const Command& command, sf::Time delta_time) = 0;
};


#endif /* INPUTCOMPONENT_H_ */
