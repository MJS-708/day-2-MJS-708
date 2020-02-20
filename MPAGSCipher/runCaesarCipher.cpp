#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>


std::string runCaesarCipher( const std::string& inputText,
int key, const bool encrypt )
{

  if (encrypt){
    std::cout << "Encrypting text" << std::endl;
  }
  else if (!encrypt){
    std::cout << "Decrypting text" << std::endl;
    key = -key;
  }


  std::string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; // Create the alphabet container and output string
  std::cout << "key is " << key << std::endl;

  std::string outputText {""};


  for (unsigned int i{0}; i < inputText.size(); i++){ // Loop over the input text

    // For each character find the corresponding position in the alphabet
    size_t found {alphabet.find(inputText.at(i))};
    if (found != std::string::npos){    // For each character find the corresponding position in the alphabet

        int newIndex {int(found) + key};   // Apply the shift (+ve or –ve depending on encrypt/decrypt)

        if(newIndex < 0){   // Wraps from A to Z for decrypting
          newIndex = 26 + newIndex;
        }
        else if (newIndex > 25){    // Wraps from Z to A for encrypting
          newIndex = newIndex % 26;
        }
        //std::cout << inputText.at(i) << " to " << alphabet.at(newIndex) << std::endl;
        outputText = outputText.append(std::string{alphabet.at(newIndex)});
      }
    else{
      std::cout << "Error: character not recognised" << std::endl;
      return "FAIL!";
    }

  }

  return outputText; // Finally (after the loop), return the output string
}
