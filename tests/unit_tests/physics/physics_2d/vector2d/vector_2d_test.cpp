#include "vector_2d_test.hpp"
#include <ostream>

TEST_F(Vector2D_TF, test_getter) {
    EXPECT_FLOAT_EQ(a.Get_X(), 1.0f);
    EXPECT_FLOAT_EQ(a.Get_Y(), 2.0f);
}

TEST_F(Vector2D_TF, test_setters_and_getters) {
    b.Set_X(69.0);
    b.Set_Y(70.0);
    EXPECT_FLOAT_EQ(b.Get_X(), 69.0f);
    EXPECT_FLOAT_EQ(b.Get_Y(), 70.0f);
}

TEST_F(Vector2D_TF, test_add_vectors) {
    Vector2d result = a + b;

    EXPECT_FLOAT_EQ(result.Get_X(), 4.0f);
    EXPECT_FLOAT_EQ(result.Get_Y(), 6.0f);
}

TEST_F(Vector2D_TF, test_add_by_scalar) {
    Vector2d result_1 = a + 1.0f;
    Vector2d result_2 = 1.0f + b;

    EXPECT_FLOAT_EQ(result_1.Get_X(), 2.0f);
    EXPECT_FLOAT_EQ(result_1.Get_Y(), 3.0f);
    EXPECT_FLOAT_EQ(result_2.Get_X(), 4.0f);
    EXPECT_FLOAT_EQ(result_2.Get_Y(), 5.0f);
}

TEST_F(Vector2D_TF, test_subtrack_vectors) {
    Vector2d result = a - b;

    EXPECT_FLOAT_EQ(result.Get_X(), -2.0f);
    EXPECT_FLOAT_EQ(result.Get_Y(), -2.0f);
}

TEST_F(Vector2D_TF, test_subtrack_by_scalar) {
    Vector2d result_1 = a - 1.0f;
    Vector2d result_2 = 1.0f - b;

    EXPECT_FLOAT_EQ(result_1.Get_X(), 0.0f);
    EXPECT_FLOAT_EQ(result_1.Get_Y(), 1.0f);
    EXPECT_FLOAT_EQ(result_2.Get_X(), -2.0f);
    EXPECT_FLOAT_EQ(result_2.Get_Y(), -3.0f);
}

TEST_F(Vector2D_TF, test_multiply_by_scalar) {
    Vector2d result_1 = a * 2.0f;
    Vector2d result_2 = 2.0f * b;

    EXPECT_FLOAT_EQ(result_1.Get_X(), 2.0f);
    EXPECT_FLOAT_EQ(result_1.Get_Y(), 4.0f);
    EXPECT_FLOAT_EQ(result_2.Get_X(), 6.0f);
    EXPECT_FLOAT_EQ(result_2.Get_Y(), 8.0f);
}

TEST_F(Vector2D_TF, test_divide_by_scalar) {
    Vector2d result = b/2u;
    EXPECT_FLOAT_EQ(result.Get_X(), 1.5f);
    EXPECT_FLOAT_EQ(result.Get_Y(), 2.0f);
}

TEST_F(Vector2D_TF, test_is_equal_operator) {
    Vector2d copy_vec = a;
    EXPECT_FLOAT_EQ(copy_vec.Get_X(), a.Get_X());
    EXPECT_FLOAT_EQ(copy_vec.Get_Y(), a.Get_Y());
}

TEST_F(Vector2D_TF, test_os_operator) {
    std::ostringstream  oss;
    oss << a;
    EXPECT_EQ(oss.str(), "(1,2)");
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

TEST_F(Vector2D_TF, test_dot_product) {
    float c = a.dot_product(b);
    EXPECT_FLOAT_EQ(c, 11.0f);
}

TEST_F(Vector2D_TF, test_cross_product) {
    float c = a.cross_product(b);
    EXPECT_FLOAT_EQ(c, -5.0f);
}

