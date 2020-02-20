#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <locale>
#include <cctype>


bool processCommandLine( //function to parse command line arguments
  const std::vector<std::string>& args,
  bool& helpRequested,
  bool& versionRequested,
  std::string& inputFileName,
  std::string& outputFileName,
  bool& encrypt,
  int& key,
  bool& closeProgram )//
  {

    int checkCipherArg {0};

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

      else if(args.at(i) == "--encrypt" || args.at(i) == "-e"){
        encrypt = true;
        //std::cout << "Encrypting text" << std::endl;
        ++checkCipherArg; //makes variable non zero so know have a encrypt/decrypt arg
        //std::cout << "Encrypting text" << std::endl;
      }

      else if(args.at(i) == "--decrypt" || args.at(i) == "-d"){
        encrypt = false;
        //std::cout << "Decrypting text" << std::endl;
        ++checkCipherArg; //makes variable non zero so know have a encrypt/decrypt arg
        //std::cout << "Decrypting text" << std::endl;
      }

      else if(args.at(i) == "--key" || args.at(i) == "-k"){
        if(i+1 > args.size()-1 || args.at(i+1)[0] == '-'){ //Checks that there is an argument after -i.... need [0] to change to character from string
          std::cout << "[error] -k}--key requires an integer argument" << std::endl;
          }
        else{
          key = std::stoull(args.at(i+1));
          //std::cout << "Key is " << key << std::endl;
        }
      }

    }

    if (key == 0 || checkCipherArg == 0){
      closeProgram = true;
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
        << "                   Stdout will be used if not supplied\n\n"
        << "                   Stdout will be used if not supplied\n\n"
        << "  -k|--key         Integer [0,25] to us as the Key for the cipher\n\n"
        << "  -e|--encrypt     Encrypts the input text\n\n"
        << "  -d|--decrypt     Decrypts the input text\n\n";


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
