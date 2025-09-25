#include "util/bisection.h"
#include <gtest/gtest.h>
#include <stdexcept>

// Use regular functions, not member functions
double func1(double x) {
    return std::pow(x, 4);        
}

double func2(double x) {
    return x - 2.0;  // Root at x = 2
}

double func3(double x) {
    return std::sin(x);  // Root at x = 0
}

class BisectionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }
};

TEST_F(BisectionTest, FirstFunction) {
    double a = -1.0;  // Changed to negative to capture root at 0
    double b = 5.0;

    double bisection_result = bisect(func1, a, b);
    double exact_result = 0.0;

    EXPECT_NEAR(exact_result, bisection_result, 1e-4);
}

TEST_F(BisectionTest, SecondFunction) {
    double a = 0.0;
    double b = 5.0;

    double bisection_result = bisect(func2, a, b);
    double exact_result = 2.0;

    EXPECT_NEAR(exact_result, bisection_result, 1e-4);
}

TEST_F(BisectionTest, ThirdFunction) {
    double a = -1.0;
    double b = 1.0;

    double bisection_result = bisect(func3, a, b);
    double exact_result = 0.0;

    EXPECT_NEAR(exact_result, bisection_result, 1e-4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
