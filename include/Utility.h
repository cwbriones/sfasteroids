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

const float PI = 3.1415926;

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

float radiansToDegrees(float radians);
float degreesToRadians(float degrees);

void centerOrigin(sf::Transformable* transformable);
void centerOrigin(sf::Text& text);
void centerOrigin(sf::Shape* object);

const float kFloatEpsilon = 0.01f;
bool isZero(float f);

// Standard Vector operations

void rotate(sf::Vector2f& vector, float angle);
sf::Vector2f getRotated(float angle);

float dot(sf::Vector2f left, sf::Vector2f right);
float magnitude(sf::Vector2f vector);

float length(sf::Vector2f vector);
void setLength(sf::Vector2f& vector, float len);

bool areOrthogonal(sf::Vector2f left, sf::Vector2f right);
sf::Vector2f getOrthogonalVector(sf::Vector2f vector);

void normalize(sf::Vector2f& vector);
sf::Vector2f unit(sf::Vector2f& vector);
sf::Vector2f unitInDirection(float angle);

sf::Vector2f getOrthonormalVector(sf::Vector2f vector);

};

#endif /* UTILITY_H_ */
