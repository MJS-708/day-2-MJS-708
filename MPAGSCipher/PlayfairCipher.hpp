#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

// Standard library includes
#include <string>
#include <vector>
#include <algorithm>
#include <map>

// Our project headers
#include "CipherMode.hpp"
#include "CipherBase.hpp" // part of cipher base class

using Letter2Coord = std::map< char, std::pair<int, int>>; //type for letters to coord datamember
using Coord2Letter = std::map<std::pair<int, int>, char>;

/**
 * \file PlayfairCipher.hpp
 * \brief Contains the declaration of the PlayfairCipher class
 */

/**
 * \class PlayfairCipher
 * \brief Encrypt or decrypt text using the Caesar cipher with the given key
 */
class PlayfairCipher : public CipherBase { // part of cipher base class
  public:
    /**
     * Create a new PlayfairCipher with the given key
     *
     * \param inputKey the key to use in the cipher
     */

    explicit PlayfairCipher( const std::string& inputKey );


    /**
     * Function to conver j to i in text
     *
     * \param text to convert J to I in
     * \return text with Js converted to I
     */
    std::string jToI (std::string& text) const;


    /**
     * Constructor to set the key
     *
     * \param key the inputKey to use in the cipher
     */
    void setKey (const std::string& inputKey);


    /**
     * Function to apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param Cipher whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher( const std::string& inputText, const Cipher mode ) const override; //overrides function in cipher base type

    private: //Private as not needed by user

      /**
      *Data member key_ is the key as type string used in the cipher
      * Accessed using .key_
      **/
      std::string key_; //key for caesar cipher as int

      /**
      *Data member alphabet_ is a string containing the alphabet
      * Accessed using .alphabet_
      **/
      std::string alphabet_ {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; // Create the alphabet container and output string

      Letter2Coord letterMap_;
      Coord2Letter coordMap_;

};

#endif
