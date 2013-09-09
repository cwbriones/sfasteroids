#include "Utility.h"
#include <cmath>

namespace Utility {

void clampVector(sf::Vector2f& vector, float max){
    float mag = magnitude(vector);
    
    if (mag > max * max) {
        vector *= max/static_cast<float>(sqrt(mag));
    }
}

float getAngle(sf::Vector2f vector){
    return PI + atan2(vector.y, vector.x);
}

float radiansToDegrees(float radians){
    return radians * 180.f / PI;
}

float degreesToRadians(float degrees){
    return degrees * PI/180.f;
}

void rotate(sf::Vector2f& vector, float angle){
    sf::Vector2f old(vector);

    vector.x = old.x * cos(angle) - old.y * sin(angle);
    vector.y = old.x * sin(angle) + old.y * cos(angle);
}

sf::Vector2f getRotated(sf::Vector2f vector, float angle){
    sf::Vector2f newvector(vector);
    rotate(newvector, angle);

    return newvector;
}

sf::Vector2f unitInDirection(float angle){
    sf::Vector2f vector(1.0f, 0.f);
    rotate(vector, angle);

    return vector;
}

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

float dot(sf::Vector2f left, sf::Vector2f right){
    return left.x * right.x + left.y * right.y;
}

float magnitude(sf::Vector2f vector){
    return vector.x * vector.x + vector.y * vector.y;
}

float length(sf::Vector2f vector){
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

void setLength(sf::Vector2f& vector, float len){
    vector *= len/length(vector);
}

bool areOrthogonal(sf::Vector2f left, sf::Vector2f right){
    return isZero(dot(left, right));
}

inline sf::Vector2f getOrthogonalVector(sf::Vector2f vector){
    return sf::Vector2f(-1.f * vector.y, vector.x);
}

void normalize(sf::Vector2f& vector){
    vector /= length(vector);
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
