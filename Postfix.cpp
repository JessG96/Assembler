#include <iostream>
#include "../string/string.hpp"
#include "stack.hpp"
#include <cassert>
#include <fstream>

int main (int, argc, char* argv[])
{
  if(argc <= 3 & argc != 1)                                          //checking to see if there are three or less arguments argc <= 3 && argc != 1
  {
    std::ifstream infix (arv[1]);                                    //obtaining input from argv[1], calling it input    
    char buffer[200];                                                //creating a character array called buffer of size 200    
    String Result;                                                   //creating a string object called result tostore the result of inToPost
    std::ofstream out;                                      
    
    if(argc == 3)                                                    //if there are three arguments
    {
      out.open(argv[2]);                                             //open a new file with the third argument
    }
    
    while(infix.getline(buffer, 200))
    {
      Result = inToPost(buffer);                                     //changing buffer from infix to postfix by passing buffer into inToPost and store it to Result
      if(argc == 3)                                                  //if there are three qrguments
      {
        out << "Infix Expression: " << buffer << std::endl;          //if the condition is true output the infix expression, buffer, to the file created
        out << "Postfix Expression: " << Result << std::endl;        //output the postfix expression, Result, to the file created
      }
      else                                                           //when the if condition is false
      {
        std::cout << "Infix Expression: " << buffer << std::endl;    //when if condition is false print out infix, buffer, to the screen, and not a file
        std::cout << "Postfix Expression :" << Result << std::endl;  //print out the postfix, Result to the screen andnot the file
     }
    }
  if(argc == 3)
  {
    out.close();
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//TEST CASES

String A(" ( ( a + ( b * c ) ) - d ) ;");
String B;

B = inToPost(A);

assert(B == "a b c * + d -");
///////////////////////////////////////////////////////////////

String C(" ( ( a + ( b / c ) ) - ( d * e ) ) ;");
String D;

D inToPost(C);

assert(D == "a b c / + d e * -");
////////////////////////////////////////////////////////////////

String E(" ( ( ( (Ax * b ) + ( cd / e ) ) - f ) + g );");
String F;

F = inToPost(E);

assert(F == "Ax b * cd e / + f - g +");
/////////////////////////////////////////////////////////////////

String G(" ( ( ( ( ( ( c * b ) / ax ) + f ) - j ) + ( h * g ) ) - c ;");
String H;

assert(H == "c b * ax / f + j - h g * + c -");

std::cout << "Infix to Postfix Called!" << std::endl;
}



