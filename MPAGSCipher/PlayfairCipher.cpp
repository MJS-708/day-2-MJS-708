
// Standard library includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <typeinfo>
#include <iterator>

// Out project headers
#include "PlayfairCipher.hpp"

//Create a new PlayfairCipher with the given key
PlayfairCipher::PlayfairCipher( const std::string& inputKey ){
  setKey(inputKey); //sets key_ from setKey
}

//Function to conver J to I
std::string PlayfairCipher::jToI( std::string& text) const
{
  std::transform(text.begin(), text.end(), text.begin(), //transform algorithm
                   [](unsigned char x) -> unsigned char { //lambda function, '->' sets return type... x iterates
                     if(x == 'J'){return('I');} //converts J to I
                     else{return(x);} //returns value
                   }); //lambda function
  return(text);
}

int gridDim {5};

void PlayfairCipher::setKey(const std::string& inputKey) {
  // store the original key
  key_ = inputKey;
  //std::cout << key_ << std::endl;

  // Append the alphabet
  key_ = key_.append(alphabet_);
  //std::cout << key_ << std::endl;

  // Make sure the key is upper case
  std::transform(key_.begin(), key_.end(), key_.begin(), ::toupper); //converts key to uppercase
  //std::cout << key_  << std::endl;

  // Remove non-alpha characters

  // reorder key_string so alphabet chars at start and return iter to start of chars to erase
  auto iter = std::remove_if(key_.begin(), key_.end(), [](unsigned char x){return !std::isalpha(x);});
  // actually erase
  key_.erase(iter, key_.end());
  //std::cout << key_  << std::endl;

  // Change J -> I
  key_ = PlayfairCipher::jToI(key_);
  std::cout << key_  << std::endl;


  // Remove duplicated letters
  std::string dupLetters {}; //initialises string for duplicated letters
  auto iter1 = std::remove_if(key_.begin(), key_.end(), [&dupLetters](unsigned char x){
    if (dupLetters.find(x) == std::string::npos){ // if x not in the dupLetters
      dupLetters += x;
      return(false);}
    else{
      return(true);}
    });
  key_.erase(iter1, key_.end());
  std::cout << key_  << std::endl;


  // Store the coords of each letter
  int row {};
  int col{};
  std::pair<int, int> coords {};


  for (unsigned int i{0}; i < key_.size(); i++){ // Loop over the input text
    row = (i/gridDim); //because using int this gets rounded down
    col = i%gridDim;
    coords = std::pair<int, int> (row, col);

    //letterMap_ and coordMap_ are maps defined as data members in header file
    letterMap_.insert(std::make_pair(key_[i], coords)); //std::make_pair joins into pair
    coordMap_.insert(std::make_pair(coords, key_[i]));
  }

  //testing iterator
  for(auto iter2 {letterMap_.begin()}; iter2 != letterMap_.end(); ++iter2) {
    std::cout << "Letter: " << (*iter2).first << ", Row: " << (*iter2).second.first // ()*iter2).first - key in *iter2 position
    << ", Col: " << (*iter2).second.second << std::endl; //(*iter2).second.second - value at 2nd values position in *iter2 position
  }
  //testing iterator
  for(auto iter2 {coordMap_.begin()}; iter2 != coordMap_.end(); ++iter2) {
    std::cout << "Row: " << (*iter2).first.first << ", Col: "
    << (*iter2).first.second << ", Letter:" << (*iter2).second << std::endl;
  }
}



std::string PlayfairCipher::applyCipher( const std::string& inputText, const Cipher mode ) const
{
  std::string cipheredText {inputText}; //create new string to change during ciphering

  // Change J -> I
  cipheredText = PlayfairCipher::jToI(cipheredText);
  //std::cout << cipheredText << std::endl;

  // if the size of input is odd, add a trailing Z
  if (cipheredText.length() %2 > 0){
    cipheredText += 'Z';
  }

  // If repeated chars in a digraph add an X or Q if XX
  std::vector<std::string> digraph;
  for (unsigned int i{0}; i < cipheredText.size(); i+=2){ // Loop over the cipheredText
    std::cout << i << std::endl;
    if(cipheredText[i] == cipheredText[i+1]){ //If same letters in digraph
      if(cipheredText[i] == 'X'){ //and both are X
        digraph.push_back(cipheredText.at(i) + std::string("Q")); //append first letter and a Q
      }
      else{
        digraph.push_back(cipheredText.at(i) + std::string("Q")); //append first letter and a Q
      }
    }
    else{
      digraph.push_back(std::string() + cipheredText.at(i) + cipheredText.at(i+1)); // create string add empty string std::string()
    }
  }





  char firstLetter {};
  char secondLetter {};

  //std::pair<int, int> firstCoord {};
  //std::pair<int, int> secondCoord {};


  auto iterCoord = coordMap_.find(std::pair<int, int> (0, 0)); //create iterator to use for searching coordMap_
  char letter {}; //Initialise letter variable to store letter at new coordinate

  cipheredText = "";

  // Loop over the input in Digraphs
  for(unsigned int i{0}; i < digraph.size(); ++i){
    std::cout << digraph[i] << std::endl; // prints digraph

    // - Find the coords in the grid for each digraph
    firstLetter = digraph[i].at(0); //first letter in digraph
    //std::cout << firstLetter << std::endl;
    auto iter = letterMap_.find(firstLetter); //iterator of first letter in key
    int row1 {iter->second.first}; // Does same as (*iter).second.second
    int col1  {(*iter).second.second};
    //std::cout << row1  << " : " << col1 << std::endl;

    secondLetter = digraph[i].at(1);
    //std::cout << secondLetter << std::endl;
    iter = letterMap_.find(secondLetter); //iterator of first letter in key
    int row2  {(*iter).second.first};
    int col2 {(*iter).second.second};
    //std::cout << row2  << " : " << col2 << std::endl;

    //Find whether encrypting or decrypting
    int shift {1}; //for decrypting


    // - Apply the rules to these coords to get 'new' coords
    if(mode == Cipher::decrypt){
      shift = gridDim-1;
    }

    //std::cout << "shift is " << shift << std::endl;

    if (row1 == row2){ //If letters on same row rule
      col1 = (col1 +shift) %gridDim;
      col2 = (col2 +shift) %gridDim;
    }

    else if (col1 == col2){ //If letters on same col rule
      row1 = (row1 + shift) %gridDim;
      row2 = (row2 + shift) %gridDim;
    }

    else{ //If letters in rectangle
      // Rectangle/Square - so keep the rows the same and swap the columns
      // (NB the operation is actually the same regardless of encrypt/decrypt
      // since applying the same operation twice gets you back to where you were)
      std::swap( col1, col2 );
    }

    std::cout << "Ciphered" << std::endl;

    //std::cout << firstLetter << std::endl;
    //std::cout << row1  << " : " << col1 << std::endl;
    iterCoord = coordMap_.find(std::pair<int, int> (row1, col1)); //iterator of first letter in key
    letter = (*iterCoord).second;
    //std::cout << firstLetter << " to " << letter << std::endl;
    cipheredText += letter;

    //std::cout << secondLetter << std::endl;
    //std::cout << row2  << " : " << col2 << std::endl;
    iterCoord = coordMap_.find(std::pair<int, int> (row2, col2)); //iterator of first letter in key
    letter = (*iterCoord).second;
    //std::cout << secondLetter << " to " << letter << std::endl;
    cipheredText += letter;

    //std::cout << cipheredText << std::endl;

  }
  std::cout << cipheredText << std::endl;

  return cipheredText;
}
