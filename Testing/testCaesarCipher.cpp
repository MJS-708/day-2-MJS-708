//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"

/*
Check that each part of caesarCipher class works
    The text is encrypted and decrypted appropriate by appropriate length
        key is private so can not get key value back
    DO NOT NEED to check file opens as that check is written into mpags-cipher.cpp main program
*/

std::string text {"BOY"}; //sufficient text to check wrapping on decrytp and encrypt
std::string transformed_text {""}; //Initialise string in memory for ciphered text

TEST_CASE("If key is in string form it tranforms text correctly", "[alphanum]"){
  CaesarCipher cipherObject {"5"}; //initialising class with key of 5

  transformed_text = cipherObject.applyCipher(text, Cipher::encrypt); //Alters transformed text according to cipher

  REQUIRE(transformed_text == "GTD"); // BOY + 5 letters for each character

  transformed_text = cipherObject.applyCipher(text, Cipher::decrypt); //Alters transformed text according to cipher

  REQUIRE(transformed_text == "WJT"); // BOY - 5 letters for each character

  std::cout << "Caesar cipher decrypted and encrypter correctly!" << std::endl; //signifies end of TEST_CASE at command line
}
