#pragma once

#include <gtest/gtest.h>
#include "rigid_body.hpp"

class RigidBody_TF : public ::testing::Test{
    protected:
        RigidBody rigid_body;
        void SetUp() override {
            rigid_body = RigidBody(2.0f, Point2d(0,0), Vector2d(0,0), Vector2d(0,0), Vector2d(0,0));
        }
        void TearDown() override {}
};
