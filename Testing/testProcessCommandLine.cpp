//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <locale>
#include <cctype>


// Headers file
#include "ProcessCommandLine.hpp"
#include "CipherMode.hpp"


ProgramSettings arguments {false, false, "", "", Cipher::encrypt, "", false}; // which keep changing and being changed back during code

std::string testFileName {"Test.txt"};


TEST_CASE("Help argument -h and --help is read", "[alphanumeric]"){

  processCommandLine(std::vector<std::string> {"-h"}, arguments);

  REQUIRE(arguments.helpRequested == true);

  arguments.helpRequested = false; // reset to false
  processCommandLine(std::vector<std::string> {"--help"}, arguments);

  REQUIRE(arguments.helpRequested == true);

  arguments.helpRequested = false; // reset to false so doesn't keep printing in all other TEST_CASEs

  std::cout << "help test complete" << std::endl; //signifies end of TEST_CASE at command line
  }



TEST_CASE("Version argument is read", "[alphanumeric]"){

  processCommandLine(std::vector<std::string> {"--version"}, arguments);

  REQUIRE(arguments.versionRequested  == true);

  arguments.versionRequested = false; // reset to false so doesn't keep printing in all other TEST_CASEs

  std::cout << "Version test complete" << std::endl; //signifies end of TEST_CASE at command line
  }



TEST_CASE("Encrypt argument -d and --decrypt is read", "[alphanumeric]"){

  processCommandLine(std::vector<std::string> {"-d"}, arguments);

  REQUIRE(arguments.mode == Cipher::decrypt);

  arguments.mode = Cipher::encrypt;
  processCommandLine(std::vector<std::string> {"--decrypt"}, arguments);

  REQUIRE(arguments.mode == Cipher::decrypt);

  std::cout << "Decrypt test complete" << std::endl; //signifies end of TEST_CASE at command line
  }



TEST_CASE("Encrypt argument -e and --encrypt is read", "[alphanumeric]"){

  processCommandLine(std::vector<std::string> {"-e"}, arguments);

  REQUIRE(arguments.mode == Cipher::encrypt);

  arguments.mode = Cipher::decrypt; // reset to decrypt
  processCommandLine(std::vector<std::string> {"--encrypt"}, arguments);

  REQUIRE(arguments.mode == Cipher::encrypt);

    std::cout << "Encrypt test complete" << std::endl; //signifies end of TEST_CASE at command line
  }




TEST_CASE("Encrypt argument -k is read and fails if necessary", "[alphanumeric]"){

  std::string keyVal {5};

  processCommandLine(std::vector<std::string> {"-k", keyVal}, arguments);

  REQUIRE(arguments.key == keyVal);


  processCommandLine(std::vector<std::string> {"-key", "-v"}, arguments); //Test scenario where no key given

  REQUIRE(arguments.closeProgram == true); //As no string after -k

  arguments.closeProgram = false;

  std::cout << "Key test complete (correct key and close programe with no key!)" << std::endl; //signifies end of TEST_CASE at command line
  }
  // Checks gives correct key value



TEST_CASE("input file argument is read", "[alphanumeric]"){

  processCommandLine(std::vector<std::string> {"-i", testFileName}, arguments);

  REQUIRE(arguments.inputFileName == testFileName);

  processCommandLine(std::vector<std::string> {"-i", "-v"}, arguments); //Test scenario where no file name given

  REQUIRE(arguments.inputFileName.empty()); //As no string after -i

  std::cout << "Input file test complete (correct file name and empty if no argument after)" << std::endl; //signifies end of TEST_CASE at command line
  }



TEST_CASE("output file argument is read", "[alphanumeric]"){

  processCommandLine(std::vector<std::string> {"-o", testFileName}, arguments);

  REQUIRE(arguments.outputFileName == testFileName);


  processCommandLine(std::vector<std::string> {"-o", "-v"}, arguments); //Test scenario where no file name given

  REQUIRE(arguments.outputFileName.empty()); //As no string after -i

  std::cout << "Output file test complete (correct file name and empty if no argument after)" << std::endl; //signifies end of TEST_CASE at command line
  }
