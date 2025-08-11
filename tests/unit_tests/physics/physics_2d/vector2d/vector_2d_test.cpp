#include "vector_2d_test.hpp"

TEST_F(Vector2D_TF, add_vectors) {
    Vector2d result = a + b;

    EXPECT_FLOAT_EQ(result._x, 4.0f);
    EXPECT_FLOAT_EQ(result._y, 6.0f);
}

TEST_F(Vector2D_TF, add_by_scalar) {
    Vector2d result_1 = a + 1.0f;
    Vector2d result_2 = 1.0f + b;

    EXPECT_FLOAT_EQ(result_1._x, 2.0f);
    EXPECT_FLOAT_EQ(result_1._y, 3.0f);
    EXPECT_FLOAT_EQ(result_2._x, 4.0f);
    EXPECT_FLOAT_EQ(result_2._y, 5.0f);
}

TEST_F(Vector2D_TF, subtrack_vectors) {
    Vector2d result = a - b;

    EXPECT_FLOAT_EQ(result._x, -2.0f);
    EXPECT_FLOAT_EQ(result._y, -2.0f);
}

TEST_F(Vector2D_TF, subtrack_by_scalar) {
    Vector2d result_1 = a - 1.0f;
    Vector2d result_2 = 1.0f - b;

    EXPECT_FLOAT_EQ(result_1._x, 0.0f);
    EXPECT_FLOAT_EQ(result_1._y, 1.0f);
    EXPECT_FLOAT_EQ(result_2._x, -2.0f);
    EXPECT_FLOAT_EQ(result_2._y, -3.0f);
}

TEST_F(Vector2D_TF, multiply_by_scalar) {
    Vector2d result_1 = a * 2.0f;
    Vector2d result_2 = 2.0f * b;

    EXPECT_FLOAT_EQ(result_1._x, 2.0f);
    EXPECT_FLOAT_EQ(result_1._y, 4.0f);
    EXPECT_FLOAT_EQ(result_2._x, 6.0f);
    EXPECT_FLOAT_EQ(result_2._y, 8.0f);
}

TEST_F(Vector2D_TF, divide_by_scalar) {
    Vector2d result = b/2u;
    EXPECT_FLOAT_EQ(result._x, 1.5f);
    EXPECT_FLOAT_EQ(result._y, 2.0f);
}

TEST_F(Vector2D_TF, is_equal_operator) {
    Vector2d copy_vec = a;
    EXPECT_FLOAT_EQ(copy_vec._x, a._x);
    EXPECT_FLOAT_EQ(copy_vec._y, a._y);
}

TEST_F(Vector2D_TF, test_length) {
    EXPECT_FLOAT_EQ(a.length(), 2.236068f);
    EXPECT_FLOAT_EQ(b.length(), 5.0f);
}

TEST_F(Vector2D_TF, test_length_squared) {
    EXPECT_FLOAT_EQ(a.length_squared(), 5.0f);
    EXPECT_FLOAT_EQ(b.length_squared(), 25.0f);
}

TEST_F(Vector2D_TF, test_normalize) {
    a.normalize();
    Vector2d c = b.normalized();
    EXPECT_FLOAT_EQ(a.length(), 1.0f);
    EXPECT_FLOAT_EQ(c.length(), 1.0f);
}

TEST_F(Vector2D_TF, test_normalize_zeroes_case) {
    a = Vector2d(0,0);
    b = Vector2d(0,0);
    a.normalize();
    Vector2d c = b.normalized();
    EXPECT_FLOAT_EQ(a.length(), 0.0f);
    EXPECT_FLOAT_EQ(c.length(), 0.0f);
}

TEST_F(Vector2D_TF, teest_dot_product) {
    float c = a.dot_product(b);
    EXPECT_FLOAT_EQ(c, 11.0f);
}

TEST_F(Vector2D_TF, teest_cross_product) {
    float c = a.cross_product(b);
    EXPECT_FLOAT_EQ(c, -5.0f);
}

