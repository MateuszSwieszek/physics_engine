#include "vector2d.hpp"

Vector2d::Vector2d():_x(0), _y(0){};
Vector2d::Vector2d(float x, float y):_x(x), _y(y){};
float Vector2d::Get_X() const{
    return _x;
}
float Vector2d::Get_Y() const{
    return _y;
}
void Vector2d::Set_X(float x){
    _x = x;
}
void Vector2d::Set_Y(float y){
    _y = y;
}
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

float Vector2d::length_squared() const{
    return _x*_x + _y*_y;
}

float Vector2d::length() const{
    return std::sqrt(length_squared());
}

void Vector2d::normalize(){
    auto len = length();
    if(len != 0.0)
        *this = *this/len;
}

float Vector2d::dot_product(Vector2d other) const{
    return _x*other._x + _y*other._y;
}

float Vector2d::cross_product(Vector2d other) const{
    return _x*other._x - _y*other._y;
}

Vector2d Vector2d::normalized() const{
    auto len = length();
    Vector2d result(0,0);
    if(len != 0.0)
        result =  *this/length();
    return result;
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
std::ostream& operator<<(std::ostream &os, const Vector2d v){
    os << "(" << v._x << "," << v._y << ")";
    return os;
}