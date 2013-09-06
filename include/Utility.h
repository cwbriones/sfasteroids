#ifndef UTILITY_H_
#define UTILITY_H_

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Shape.hpp>

#define DEBUG_BUILD
#ifndef DEBUG_BUILD
#define RELEASE_BUILD
#endif

namespace Utility {

template<class T>
T clamp(T x, T low, T high){
    assert(low < high);

    if (x < low){
        return low;
    }
    else if (x > high){
        return high;
    }
    return x;
}

void centerOrigin(sf::Text& text);
void centerOrigin(sf::Shape* object);

const float kFloatEpsilon = 0.01f;
bool isZero(float f);

// Standard Vector operations

float dot(sf::Vector2f left, sf::Vector2f right);
float magnitude(sf::Vector2f vector);
float length(sf::Vector2f vector);

bool areOrthogonal(sf::Vector2f left, sf::Vector2f right);
sf::Vector2f getOrthogonalVector(sf::Vector2f vector);

void normalize(sf::Vector2f& vector);
sf::Vector2f unit(sf::Vector2f& vector);

sf::Vector2f getOrthonormalVector(sf::Vector2f vector);

};

#endif /* UTILITY_H_ */
