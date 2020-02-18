#include <string>
#include <locale>
#include <cctype>

std::string transformChar(char in_char){
  std::string next_char {};

  if(std::isalnum(in_char)==true){   // Takes char as input and outputs uppercase value
    in_char = toupper(in_char);

    switch(in_char){ //    - Change numbers to words
      case '0':
        next_char = "ZERO";
        break;
      case '1':
        next_char = "ONE";
        break;
      case '2':
        next_char = "TWO";
        break;
      case '3':
        next_char = "THREE";
        break;
      case '4':
        next_char = "FOUR";
        break;
      case '5':
        next_char = "FIVE";
        break;
      case '6':
        next_char = "SIX";
        break;
      case '7':
        next_char = "SEVEN";
        break;
      case '8':
        next_char = "EIGHT";
        break;
      case '9':
        next_char = "NINE";
        break;
      default:
        next_char = in_char;
    }
  }
  return next_char;
}
