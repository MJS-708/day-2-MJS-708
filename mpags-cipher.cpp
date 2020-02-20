// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <locale>
// For std::isalpha and std::isupper
#include <cctype>
#include <fstream> //file stream
#include <locale>


// Our project headers
#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaesarCipher.hpp"


//! Transliterate char to string
std::string transformChar(const char in); //Takes character as input and outputs Uppercase

//function to parse command line arguments
bool processCommandLine(
  const std::vector<std::string>& args,
  bool& helpRequested,
  bool& versionRequested,
  std::string& inputFileName,
  std::string& outputFileName,
  bool& encrypt,
  int& key,
  bool& closeProgram );

//function
std::string runCaesarCipher( const std::string& inputText,
  const size_t key, const bool encrypt );

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFileName {""}; //set names before function so changed out of scope
  std::string outputFileName {""};
  bool encrypt {false};
  int key {};
  bool closeProgram {false};

  std::string transformed_text {""}; // allocate memory for string output
  char in_char{'x'}; // allocated memory address for each character in input file

  processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFileName, outputFileName, encrypt, key, closeProgram);

  if (closeProgram){
    std::cout << "Program is ending\n" << "Check provided key and/or argument to indicate encrpytion/decrpytion" << std::endl;
    return 0;
  }

//INPUTTING CIPHER
  if(inputFileName.empty()){
    std::cout << "Give text argument to encrypt/decrypt" << std::endl;
    while(std::cin >> in_char) //iterate over each character in command line input
    {
      transformed_text = transformed_text.append(transformChar(in_char)); //Appends transformed character to output text
    }
  }
  else{
    std::ifstream in_file {inputFileName}; //Load file
    bool ok_to_read = in_file.good(); //Check that file is readable

    if (ok_to_read){ //if file is readable...
      while(in_file >> in_char) //iterate over each character in file input
      {
        transformed_text = transformed_text.append(transformChar(in_char)); //Appends transformed character to output text
      }
    }
    else{
      std::cout << "input file is unreadable" << std::endl;
    }
  }


  transformed_text = runCaesarCipher(transformed_text, key, encrypt); //transformed text is now the deciphered text returned by the caesar cipher

  //std::cout << transformed_text << std::endl;

//OUTPUTTING CIPHER
  if(outputFileName.empty()){
      std::cout << transformed_text << std::endl;
    }
    else{
    std::string name {outputFileName}; // name of out file
    std::ofstream out_file {name}; //create out file

    bool ok_to_write = out_file.good(); //can we write to file (write permissions, it exists etc)... returns true if can write

    if (ok_to_write){
      out_file << transformed_text << std::endl; // outputs text into the file

      out_file.close();
    }
    else{
      std::cout << "unable to write to output file" << std::endl;
    }
  }

  return 0;
}
