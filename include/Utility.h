#ifndef UTILITY_H_
#define UTILITY_H_

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Shape.hpp>

namespace Utility {

void centerOrigin(sf::Text& text);
void centerOrigin(sf::Shape* object);

};

#endif /* UTILITY_H_ */
