#include "bisection.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

double func1(double x) {
	return std::pow(x,4);		
}

double exact_root_func1() {
	return 0.0;
}

double func2(double x) {
	return std::pow(x,4);		
}

double exact_root_func2() {
	return 0.0;
}

double func3(double x) {
	return std::pow(x,4);		
}

double exact_root_func3() {
	return 0.0;
}

TEST_CASE("Bisection Method Test", "[math][bisection method]") {
	REQUIRE_THAT(exact_root_func1(), 
		Catch::Matchers::WithinAbsMatcher(bisect(func1, 0, 5), 1e-4));
	REQUIRE_THAT(exact_root_func2(), 
		Catch::Matchers::WithinAbsMatcher(bisect(func2, 0, 5), 1e-4));
	REQUIRE_THAT(exact_root_func3(), 
		Catch::Matchers::WithinAbsMatcher(bisect(func3, 0, 5), 1e-4));
}
