#include "Utility.h"
#include <cmath>

namespace Utility {

void centerOrigin(sf::Text& text){
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.width/2.f, bounds.height/2.f);
}

void centerOrigin(sf::Shape* shape){
    auto bounds = shape->getLocalBounds();
    shape->setOrigin(bounds.width/2.f, bounds.height/2.f);
}

bool isZero(float f){
    return fabs(f) < kFloatEpsilon;
}

inline float dot(sf::Vector2f left, sf::Vector2f right){
    return left.x * right.x + left.y * right.y;
}

inline float magnitude(sf::Vector2f vector){
    return vector.x * vector.x + vector.y * vector.y;
}

float length(sf::Vector2f vector){
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

bool areOrthogonal(sf::Vector2f left, sf::Vector2f right){
    return isZero(dot(left, right));
}

inline sf::Vector2f getOrthogonalVector(sf::Vector2f vector){
    return sf::Vector2f(-1.f * vector.y, vector.x);
}

void normalize(sf::Vector2f& vector){
    float len = length(vector);

    vector.x /= len;
    vector.y /= len;
}

sf::Vector2f unit(sf::Vector2f vector){
    sf::Vector2f unit_vec(vector);
    normalize(unit_vec);

    return unit_vec;
}

sf::Vector2f getOrthonormalVector(sf::Vector2f vector){
    sf::Vector2f ortho = getOrthogonalVector(vector);
    normalize(ortho);

    return ortho;
}

};
