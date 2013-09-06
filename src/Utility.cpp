#include "Utility.h"

namespace Utility {

void centerOrigin(sf::Text& text){
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.width/2.f, bounds.height/2.f);
}

void centerOrigin(sf::Shape* shape){
    auto bounds = shape->getLocalBounds();
    shape->setOrigin(bounds.width/2.f, bounds.height/2.f);
}

};
