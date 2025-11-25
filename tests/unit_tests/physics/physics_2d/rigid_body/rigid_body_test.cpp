#include "rigid_body_test.hpp"
#include <ostream>

TEST_F(RigidBody_TF, test_apply_force_and_integrate){
    Vector2d force(10.0f, 10.0f);
    float dt = 0.001f;
    Vector2d expected_acc = (force * rigid_body.get_inv_mass()) * dt;
    Vector2d expected_vel = expected_acc * dt;
    Vector2d expected_pos = expected_pos * dt;

    rigid_body.apply_force(force);
    rigid_body.intergrate(dt);

    EXPECT_FLOAT_EQ(rigid_body.get_pos().Get_X(), expected_pos.Get_X());
    EXPECT_FLOAT_EQ(rigid_body.get_pos().Get_Y(), expected_pos.Get_Y());

    EXPECT_FLOAT_EQ(rigid_body.get_vel().Get_X(), expected_vel.Get_X());
    EXPECT_FLOAT_EQ(rigid_body.get_vel().Get_X(), expected_vel.Get_X());
    
    EXPECT_FLOAT_EQ(rigid_body.get_acc().Get_Y(), expected_acc.Get_Y());
    EXPECT_FLOAT_EQ(rigid_body.get_acc().Get_Y(), expected_acc.Get_Y());    
}