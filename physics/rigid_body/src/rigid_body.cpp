#include "rigid_body.hpp"

RigidBody::RigidBody():_pos(0,0){};
RigidBody::RigidBody(float mass, Point2d pos, Vector2d vel, Vector2d acc, Vector2d force):_mass(mass), _pos(pos), _vel(vel), _acc(acc), _force(force){};

void RigidBody::apply_force(const Vector2d &new_force){
    _force = _force + new_force;
}
