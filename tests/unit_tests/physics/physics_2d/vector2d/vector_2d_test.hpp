#pragma once

#include <gtest/gtest.h>
#include "vector2d.hpp"

class Vector2D_TF : public ::testing::Test{
    protected:
    Vector2d a,b;

    void SetUp() override {
        a = Vector2d(1.0, 2.0);
        b = Vector2d(3.0, 4.0);
    }

    void TearDown() override {
        // np. cleanup — tu nic nie trzeba
    }
};