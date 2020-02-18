#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <locale>
#include <cctype>


bool processCommandLine( //function to parse command line arguments
  const std::vector<std::string>& args, // First input is the list of strings
  bool& helpRequested, //help requested bool arg to edit
  bool& versionRequested, //
  std::string& inputFileName, //Empty string arg to update
  std::string& outputFileName ) //
  {

    for (size_t i{0}; i < args.size(); i++){ // < as 0 index
      //std::cout << "Argument " << i << " is " << args.at(i) << std::endl; //prints commands
      //printf("Argument %i, is %s \n", i, args.at(i)); // using prints?
      
      if(args.at(i) == "--help" || args.at(i) == "-h"){ //Print help
        helpRequested = true;
        break; //if want help don't do anything else
      }

      else if(args.at(i) == "--version"){ //print version number
        versionRequested = true;
        break; //if want version don't do anything else
      }

      else if(args.at(i) == "-i"){
        //bool test{std::isalpha(test_char)};
        if(i+1 > args.size()-1 || args.at(i+1)[0] == '-'){ //Checks that there is an argument after -i that isn't another argument ('-')
          std::cout << "[error] -i requires a filename argument" << std::endl;
          }
        else{
          inputFileName = args.at(i+1); // sets input file name to value after -if (/* condition */) {
          //++i;
        }
      }

      else if(args.at(i) == "-o"){
        //bool test{std::isalpha(test_char)};
        if(i+1 > args.size()-1 || args.at(i+1)[0] == '-'){ //Checks that there is an argument after -i.... need [0] to change to character from string
          std::cout << "[error] -o requires a filename argument" << std::endl;
          }
        else{
          outputFileName = args.at(i+1); // sets input file name to value after -if (/* condition */) {
        }
      }
    }
    // Handle help, if requested
    if (helpRequested) { // equivalent to helpRequested == true
      // Line splitting for readability
      std::cout
        << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
        << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
        << "Available options:\n\n"
        << "  -h|--help        Print this help message and exit\n\n"
        << "  --version        Print version information\n\n"
        << "  -i FILE          Read text to be processed from FILE\n"
        << "                   Stdin will be used if not supplied\n\n"
        << "  -o FILE          Write processed text to FILE\n"
        << "                   Stdout will be used if not supplied\n\n";
      // Help requires no further action, so return from main
      // with 0 used to indicate success
      return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
      std::cout << "0.1.0" << std::endl;
      return 0;
    }
    return true;
  }
