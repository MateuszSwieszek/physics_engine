#include "vector2d.hpp"

using Point2d = Vector2d;

class RigidBody{
    Point2d _pos;
    Vector2d _vel;
    Vector2d _acc;
    Vector2d _force;
    float _mass;
public:
    RigidBody();
    RigidBody(float mass = 0, Point2d pos = Point2d(0,0), Vector2d vel = Vector2d(0,0), Vector2d _acc = Vector2d(0,0), Vector2d _force = Vector2d(0,0));

    void apply_force(const Vector2d &new_force);
};
