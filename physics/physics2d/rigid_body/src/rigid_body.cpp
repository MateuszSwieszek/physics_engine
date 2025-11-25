#include "rigid_body.hpp"

RigidBody::RigidBody():_pos(0,0){};
RigidBody::RigidBody(float mass, Point2d pos, Vector2d vel, Vector2d acc, Vector2d force):_mass(mass), _inv_mass(1/mass), _pos(pos), _vel(vel), _acc(acc), _force(force){};

void RigidBody::apply_force(const Vector2d &new_force){
    _force = _force + new_force;
}

void RigidBody::intergrate(float dt){
    _acc = _force * _inv_mass;
    _vel = _vel + _acc * dt;
    _pos = _pos + _vel * dt;
}

void RigidBody::set_mass(float mass){
    _mass = mass;
}