// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

// Main function of the mpags-cipher program

double multiply( const double first, const double second ) // function to return multiplication of 2 double argyments
{
  return first * second;
}

void print( const double value ) // void as prints a value but doesn't return anything (no change in memory)
{
  std::cout << “Result: “ << value << std::endl;
}

int main()
{
  double a{43.0},
  double b{21.0},
  double c{ multiply(a, b) };
  print( multiply(a, c) );

return 0;
}
