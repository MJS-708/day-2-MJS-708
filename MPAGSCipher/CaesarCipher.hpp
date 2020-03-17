#ifndef MPAGSCIPHER_CaesarCipher_HPP
#define MPAGSCIPHER_CaesarCipher_HPP

#include <iostream>
#include <string>
#include <vector>

#include "CipherMode.hpp"
#include "CipherBase.hpp"

/**
 * \file CaesarCipher.hpp
 * \brief Contains the declaration of the CaesarCipher class
 */

/**
 * \class CaesarCipher
 * \brief Encrypt or decrypt text using the Caesar cipher with the given key
 */
class CaesarCipher : public CipherBase { // Class to take key argument, creates integer from it... includes member function to apply caeesar cipher
  //Public Cipher base as part of cipher base class
  public: // needs to be public to run

  /**
   * Create a new CaesarCipher with the given key
   *
   * \param key the key to use in the cipher
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
    std::string applyCipher (const std::string& inputText, const Cipher mode ) const override; // const as doesn't change data members
    //overrides function in cipher base type

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
