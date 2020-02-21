#ifndef MPAGSCIPHER_CaesarCipher_HPP
#define MPAGSCIPHER_CaesarCipher_HPP

#include <iostream>
#include <string>
#include <vector>

#include "CipherMode.hpp"

/**
*CeasarCipher is a class type that takes a key to initialise
*/
class CaesarCipher{ // Class to take key argument, creates integer from it... includes member function to apply caeesar cipher
  public: // needs to be public to run

    /**
    *Contains explicit constructor that can take an int as key
    *then stores in the object type for use in the cipher
    \param inputKey the key to use in cipher as int type
    */
    explicit CaesarCipher(const int inputKey); // constructor - argument to pass to constructor definitions in cpp file

    /**
    *Contains explicit constructor that can take a string as key
    *then converts to int type and stores in the object type for use in the cipher
    \param inputKey the key to use in cipher as string type
    */
    explicit CaesarCipher(const std::string inputKey); //Takes a string argument to convert to int

    /**
    *Contains member function 'applyCaesarCipher' which encryts or decrypts input text
    \param inputText the text to cipher as string
    \param encrypt boolean to determine whether to encrypt (true) or decrpyt (false) input text
    */
    std::string applyCaesarCipher (const std::string& inputText, const Cipher mode ) const; //as doesn't change data members

  private: //Provate as not needed by user

    /**
    *Data member key_ is the key as type int used in the cipher
    * Accessed using .key_
    **/
    int key_; //key for caesar cipher as int

    /**
    *Data member alphabet_ is a string containing the alphabet
    * Accessed using .alphabet_
    **/
    std::string alphabet_ {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; // Create the alphabet container and output string

};

#endif //MPAGSCIPHER_TRANSFORMCHAR_HPP is now defined
