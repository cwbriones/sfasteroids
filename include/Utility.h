#ifndef UTILITY_H_
#define UTILITY_H_

#include <SFML/Graphics/Text.hpp>

void centerOrigin(sf::Text& text){
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.width/2.f, bounds.height/2.f);
}

#endif /* UTILITY_H_ */
