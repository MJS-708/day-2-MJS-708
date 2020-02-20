#ifndef MPAGSCIPHER_processCommandLine_HPP
#define MPAGSCIPHER_processCommandLine_HPP

#include <iostream>
#include <string>
#include <vector>

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

#endif //MPAGSCIPHER_TRANSFORMCHAR_HPP is now defined
