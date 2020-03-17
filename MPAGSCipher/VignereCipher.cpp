
// Standard library includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <typeinfo>
#include <iterator>

// Out project headers
#include "VignereCipher.hpp"

//Create a new PlayfairCipher with the given key
VignereCipher::VignereCipher( const std::string& inputKey ){
  setKey(inputKey); //sets key_ from setKey
}


void VignereCipher::setKey(const std::string& inputKey) {
  // store the original key
  key_ = inputKey;
  //std::cout << key_ << std::endl;

  // Make sure the key is upper case
  std::transform(key_.begin(), key_.end(), key_.begin(), ::toupper); //converts key to uppercase

  // Remove non-alpha characters

  // reorder key_string so alphabet chars at start and return iter to start of chars to erase
  auto iter = std::remove_if(key_.begin(), key_.end(), [](unsigned char x){return !std::isalpha(x);});
  // actually erase
  key_.erase(iter, key_.end());
  //std::cout << key_  << std::endl;

  if(key_.empty()){
    key_ = "DEFAULT";
  }

  std::cout << "KEY IS  " << key_ << std::endl;

  int pos {};
  char keyLetter; //Key letter for each character of input text

  // loop over the key
  for(unsigned int i{0}; i < key_.size(); ++i){
    keyLetter = key_.at(i);
    pos = alphabet_.find(keyLetter); // Find the letter position in the alphabet
    CaesarCipher cipherObject {pos}; // Create a CaesarCipher using this position as a key
    charLookup_.insert(std::make_pair(key_.at(i), cipherObject)); // Insert a std::pair of the letter and CaesarCipher into the lookup
  }
}





std::string VignereCipher::applyCipher( const std::string& inputText, const Cipher mode) const //prevents error from unused arg
{

  std::map<char, CaesarCipher> cipherMap;
  std::string transChar {};
  std::string outText {};
  char keyLetter; //Key letter for each character of input text

  //Loop over input text
  for(unsigned int i{0}; i < inputText.size(); ++i){
      // Find the corresponding letter in the key,
      if (i > key_.size()){
        keyLetter = key_.at(i%key_.size()); //Repeat key if shorter than input text
      }
      else{
        keyLetter = key_.at(i);
      }

      // Find the Caesar cipher from the lookup
      auto iter = charLookup_.find(keyLetter);


      // Run the (de)encryption
      transChar = iter->second.applyCipher(std::string{inputText.at(i)}, mode);

      // Add the result to the output
      outText += transChar;
    }

  return outText;
}
