//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Addition works", "[maths]"){
  REQUIRE(1+1 ==2); // Gives a passed test
}

TEST_CASE("Addition fails", "[maths]"){
  REQUIRE(1+1 ==3); //Gives a failed test
}
