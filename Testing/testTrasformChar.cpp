//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "TransformChar.hpp"

TEST_CASE("Characters are uppercases", "[alphanumeric]"){
  const std::string upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  const std::string lower {"abcdefghijklmnopqrstuvwxyz"};

  for(size_t i=0; i < upper.size(); i++){
    REQUIRE(transformChar(lower[i]) == std::string{upper[i]});
    // Checks that TransformChar makes lowercase alphabet uppercase
  }
}

TEST_CASE("Digits are transliterated", "[alphanumeric]"){
  REQUIRE(transformChar('0') == "ZERO");
  REQUIRE(transformChar('1') == "ONE");
  REQUIRE(transformChar('2') == "TWO");
  REQUIRE(transformChar('3') == "THREE");
  REQUIRE(transformChar('4') == "FOUR");
  REQUIRE(transformChar('5') == "FIVE");
  REQUIRE(transformChar('6') == "SIX");
  REQUIRE(transformChar('7') == "SEVEN");
  REQUIRE(transformChar('8') == "EIGHT");
  REQUIRE(transformChar('9') == "NINE");
  //Check that numeric values are converted to string
}

TEST_CASE("Special characters are removed", "[punctuation]"){
  const std::string specChar {"!@£$%^&*()_+-=/.,"};

  for(size_t i=0; i < specChar.size(); i++){
    REQUIRE(transformChar(specChar[i]) == "");
    // Checks that Special characters are ignored
  }
}
