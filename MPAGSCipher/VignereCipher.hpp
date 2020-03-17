#ifndef MPAGSCIPHER_VIGNERECIPHER_HPP
#define MPAGSCIPHER_VIGNERECIPHER_HPP

// Standard library includes
#include <string>
#include <vector>
#include <algorithm>
#include <map>

// Our project headers
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "CipherBase.hpp" //Cipher base class


class VignereCipher : public CipherBase { //Part of Cipher Base class
  public:
    /**
     * Create a new VignereCipher with the given key
     *
     * \param inputKey the key to use in the cipher
     */

    explicit VignereCipher( const std::string& inputKey );



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
      std::string key_; //key for Vignere cipher as int
      std::string alphabet_ {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; // Create the alphabet container and output string


      /// Lookup table
      std::map<char, CaesarCipher> charLookup_;

};

#endif
