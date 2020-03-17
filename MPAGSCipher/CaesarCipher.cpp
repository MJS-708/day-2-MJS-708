#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

// Headers file
#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

CaesarCipher::CaesarCipher(const int inputKey) // Takes key in integer form
  : key_{inputKey}{ // Can do something to input key here...
  }
CaesarCipher::CaesarCipher(const std::string inputKey) //Takes key as string
  : key_{std::stoi(inputKey)}{ // converts input key to integer from string (stoi)
  }


std::string CaesarCipher::applyCipher (const std::string& inputText, const Cipher mode ) const
{
  int newIndex {};
  std::cout << "updated key is " << key_ << std::endl;

  std::cout << "key is " << key_ << std::endl;

  std::string outputText {""};


  for (unsigned int i{0}; i < inputText.size(); i++){ // Loop over the input text

    // For each character find the corresponding position in the alphabet_
    size_t found {alphabet_.find(inputText.at(i))};
    if (found != std::string::npos){    // For each character find the corresponding position in the alphabet_

      if (mode == Cipher::encrypt){ //use enumarator to see if encrypt/decrypt
        //std::cout << "Encrypting text" << std::endl;
        newIndex = int(found) + key_;   // Apply the shift (+ve or –ve depending on encrypt/decrypt)
      }
      else if (mode == Cipher::decrypt){ //use enumarator to see if encrypt/decrypt
        //std::cout << "Decrypting text" << std::endl;
        newIndex = int(found) - key_;   // Apply the shift (+ve or –ve depending on encrypt/decrypt)
      }

      if(newIndex < 0){   // Wraps from A to Z for decrypting
        newIndex = 26 + newIndex;
      }
      else if (newIndex > 25){    // Wraps from Z to A for encrypting
        newIndex = newIndex % 26;
      }
      //std::cout << inputText.at(i) << " to " << alphabet_.at(newIndex) << std::endl;
      outputText = outputText.append(std::string{alphabet_.at(newIndex)});
      }
    else{
      std::cout << "Error: character not recognised" << std::endl;
      return "FAIL!";
    }

  }

  return outputText; // Finally (after the loop), return the output string
}
