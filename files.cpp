#include <fstream>

//output files


std::string name {"myoutputfile.txt"}; // name of out file
std::ofstream out_file {name}; //create out file

bool ok_to_write = out_file.good(); //can we write to file (write permissions, it exists etc)... returns true if can write

out_file << "Some text\n"; // outputs text into the file

file.close(); // close file

//input files

std::string name {"myinputfile.txt"};
std::ifstream in_file {name};

bool ok_to_read = in_file.good();

char inputChar {'x'};
in_file >> inputChar;
