#include <iostream>
#include <string>
#include <vector>


std::string runCaesarCipher( const std::string& inputText,
const size_t key, const bool encrypt )
{
  std::string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXZ"}; // Create the alphabet container and output string
  std::cout << "key is " << key << std::endl;
  std::cout << encrypt << std::endl;

  for (unsigned int i{0}; i < inputText.size(); i++){ // Loop over the input text

    std::cout << inputText.at(i) << std::endl;

    // For each character find the corresponding position in the alphabet
    // Apply the shift (+ve or –ve depending on encrypt/decrypt)
    // to the position, handling correctly potential wrap-around
    // Determine the new character and add it to the output string

  }

      // Finally (after the loop), return the output string
      return alphabet;
}
