#include "vector2d.hpp"

Vector2d::Vector2d():_x(0), _y(0){};
Vector2d::Vector2d(float x, float y):_x(x), _y(y){};
Vector2d Vector2d::operator+(const Vector2d &other) const{
    return Vector2d(_x + other._x, _y + other._y);
}
Vector2d Vector2d::operator+(const float scalar) const{
    return Vector2d(_x + scalar, _y + scalar);
}
Vector2d Vector2d::operator-(const Vector2d &other) const{
    return Vector2d(_x - other._x, _y - other._y);
}
Vector2d Vector2d::operator-(const float scalar) const{
    return Vector2d(_x - scalar, _y - scalar);
}
Vector2d Vector2d::operator*(const float scalar) const{
        return Vector2d(_x * scalar, _y * scalar);
}
Vector2d Vector2d::operator/(const float scalar) const{
        return Vector2d(_x / scalar, _y / scalar);
}
bool Vector2d::operator==(const Vector2d &other) const{
    return _x == other._x && _y == other._y;
}

float Vector2d::length() const{
    return std::sqrt(_x*_x + _y*_y);
}

Vector2d operator+(const float scalar, const Vector2d &other){
    return Vector2d(scalar + other._x, scalar + other._y);
}
Vector2d operator-(const float scalar, const Vector2d &other){
    return Vector2d(scalar - other._x, scalar - other._y);
}
Vector2d operator*(const float scalar, const Vector2d &other){
    return Vector2d(scalar * other._x, scalar * other._y);
}
Vector2d operator/(const float scalar, const Vector2d &other){
    return Vector2d(scalar / other._x, scalar / other._y);
}