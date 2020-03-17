#ifndef MPAGSCIPHER_processCommandLine_HPP
#define MPAGSCIPHER_processCommandLine_HPP

#include <iostream>
#include <string>
#include <vector>

#include "CipherMode.hpp"
#include "CipherType.hpp"

// Struct type to take all arguments of processCommandLine
struct ProgramSettings {
  bool helpRequested;
  bool versionRequested;
  std::string inputFileName;
  std::string outputFileName;
  Cipher mode;
  std::string key;
  bool closeProgram;
  CipherType cipherType;  ///< Flag to indicate which cipher to use (e.g. Caesar, Playfair, etc.)
};

//function to parse command line arguments
bool processCommandLine(
  const std::vector<std::string>& args,
  ProgramSettings& arguments);

#endif //MPAGSCIPHER_TRANSFORMCHAR_HPP is now defined
