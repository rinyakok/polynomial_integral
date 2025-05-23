#include <gtest/gtest.h>
#include "integrator.h"

// Test for quadratic polynomial: f(x) = 1 + 3x + 2x^2, integrate from 0 to 2
TEST(IntegratorTest, QuadraticPolynomial) {
    etl::array<float, 3> coeffs = {1.0f, 3.0f, 2.0f}; // 1 + 3x + 2x^2	
    float lower = 0.0f;
    float upper = 2.0f;
    float result = integratePolynomial(coeffs, lower, upper);
    // Indefinite integral: (2/3)x^3 + (3/2)x^2 + x
    float expected = (2.0f/3.0f)*8 + (3.0f/2.0f)*4 + 2.0f - 0.0f;   //13.333333969116211
    std::cout << "Integral result: " << result << std::endl;
    std::cout << "expected: " << expected << std::endl;
    EXPECT_NEAR(result, expected, 1e-4f);
}

// Test for cubic polynomial: f(x) = - 5 + 2x - x^2 + x^3, integrate from -1 to 1
TEST(IntegratorTest, CubicPolynomial) {
    etl::array<float, 4> coeffs = {-5.0f, 2.0f, -1.0f, 1.0f}; // - 5 + 2x - x^2 + x^3
    float lower = -1.0f;
    float upper = 1.0f;
    float result = integratePolynomial(coeffs, lower, upper);
    // Indefinite integral: (1/4)x^4 - (1/3)x^3 + x^2 - 5x
    auto F = [](float x) { return (1.0f/4.0f)*x*x*x*x - (1.0f/3.0f)*x*x*x + x*x - 5.0f*x; };  // -10.66666667
    float expected = F(1.0f) - F(-1.0f);
    std::cout << "Integral result: " << result << std::endl;
    std::cout << "expected: " << expected << std::endl;
    EXPECT_NEAR(result, expected, 1e-4f);
}

// Test for constant polynomial: f(x) = 7, integrate from 0 to 3
TEST(IntegratorTest, ConstantPolynomial) {
    etl::array<float, 1> coeffs = {7.0f}; // 7
    float lower = 0.0f;
    float upper = 3.0f;
    float result = integratePolynomial(coeffs, lower, upper);       //  21
    float expected = 7.0f * (upper - lower);
    std::cout << "Integral result: " << result << std::endl;
    std::cout << "expected: " << expected << std::endl;
    EXPECT_NEAR(result, expected, 1e-4f);
}

// Test for Long polynomial: f(x) = 2 + 3x + 4x^2 + 7x^4 + x^5, integrate from -100 to 100
TEST(IntegratorTest, LongPolynomial) {
    etl::array<float, 6> coeffs = {2.0f, 3.0f, 4.0f, 0.0f, 7.0f, 1.0f}; // 1 + 3x + 2x^2	
    float lower = -100.0f;
    float upper = 100.0f;
    float result = integratePolynomial(coeffs, lower, upper);
    // Indefinite integral: (1/6)x^6 + (7/5)x^5 + (4/3)x^3 + (3/2)x^2 + 2x
    float expected = 2.8002667e10f;   //2.8002667e+10
    std::cout << "Integral result: " << result << std::endl;
    std::cout << "expected: " << expected << std::endl;
    EXPECT_NEAR(result, expected, 1e-4f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
