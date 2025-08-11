#pragma once
#include <cmath>
#include <ostream>

class Vector2d{
        float _x, _y;

    public:
        Vector2d();
        Vector2d(float _X, float _y);

        float Get_X() const;
        float Get_Y() const;
        void Set_X(float x);
        void Set_Y(float y);

        Vector2d operator+(const Vector2d &other) const;
        Vector2d operator+(const float scalar) const;
        Vector2d operator-(const Vector2d &other) const;
        Vector2d operator-(const float scalar) const;
        Vector2d operator*(const float scalar) const;
        Vector2d operator/(const float scalar) const;
        bool operator==(const Vector2d &other) const;

        float length_squared() const;
        float length() const;
        void normalize();
        Vector2d normalized() const;
        float dot_product(Vector2d other) const;
        float cross_product(Vector2d other) const;

        friend Vector2d operator+(const float scalar, const Vector2d &other);
        friend Vector2d operator-(const float scalar, const Vector2d &other);
        friend Vector2d operator*(const float scalar, const Vector2d &other);
        friend Vector2d operator/(const float scalar, const Vector2d &other);
        friend std::ostream& operator<<(std::ostream &os, const Vector2d v);
};
