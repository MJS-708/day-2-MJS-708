//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "CipherMode.hpp"
#include "CipherBase.hpp"
#include "CaesarCipher.hpp"
#include "VignereCipher.hpp"
#include "PlayfairCipher.hpp"

/*
  Test that takes;
    cipher, the de/encrypt mode, input text and expected output
  return boolean to indicate whether matches expected
*/
bool testCipher( const CipherBase& cipher, const Cipher mode,
  const std::string& inputText, const std::string& outputText)
{
    return (cipher.applyCipher(inputText, mode) == outputText);
  }


std::string inputText {"BOY"}; //sufficient text to cipher
std::string outputText {}; //Initialise string in memory for output (different for each cipher)
std::string key {};




TEST_CASE("If caesar cipher is encrypting/decrpyting correctly", "[bool]"){

  outputText = "ERB";
  key = "3";
  REQUIRE( testCipher(CaesarCipher{key}, Cipher::encrypt, inputText, outputText) ); //requires the boolean is true

  outputText = "FKZU";
  key = "";
  REQUIRE( testCipher(PlayfairCipher{key}, Cipher::encrypt, inputText, outputText) ); //requires the boolean is true

  outputText = "LSW";
  key = "key";
  REQUIRE( testCipher(VignereCipher{key}, Cipher::encrypt, inputText, outputText) ); //requires the boolean is true
}
