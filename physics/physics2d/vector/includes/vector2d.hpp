#include <cmath>

class Vector2d{
    public:
    
        float _x, _y;

        Vector2d();
        Vector2d(float _X, float _y);

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
};
