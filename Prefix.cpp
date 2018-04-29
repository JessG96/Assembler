#include <iostream>
#include "../string/string.hpp"
#include "stack.hpp"
#include <cassert>
#include <fstream>

int main(int argc, char* argv[])
{
  if (argc <= 3 & argc != 1)                                    //checking to see if thiere are three or less arguments argc <= 3 && argc != 1
  {
   std::ifstream infix (argv[1]);                                //obtaining input from argv[1], calling it input
   char buffer[200];                                             //creating a character array called buffer of size 200
   
   String Result;                                                //creating a string object called result to store the result of inToPrefix
    
   std::ofstream out;
   if(argc == 3)                                                 //if there are three arguments
   {
    out.open(argv[2]);                                           //open a new file with the thrid argument 
   }
   while(infix.getline(buffer, 200)
   {
    Result = inToprefix(buffer);                                 //changing buffer from infix to prefix by passing buffer into inToPrefix and store it to Result
    
    if(argc == 3)                                                //if there are three arguments
    {
      out << "Infix Expression: " << buffer << std::endl;        //if the condition is true output the infix expression, buffer, to the file created
      out << "Prefix Expression: " << Result << std::endl;       //output the prefix expression, Result, to the file created
    }
    else                                                         //when the if condition is false
    {
      std::cout << "Infix Expression :" << buffer << std::endl;  //when if condition is false print out infix, buffer, to the screen, not to a file
      std::cout << "Prefix Expression :" << Result << std::endl; //print out the prefix, Result, to the screen, and not a file
    }
   }
   if(argc == 3)                                                 //if there are three arguments
   {
    out.close();                                                 //close the file        
   }
 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         
//TEXT CASES

String A("( ( a + ( b * c ) ) - d ) ;");
String B;
         
B = inToPrefix(A);
         
assert(B == "- + a * b c d");
////////////////////////////////////////////////
         
String C("( ( a + ( b / c ) ) - ( d * e ) ) ;");
String D;

D = inToPrefix(C);
         
assert(D == "- + a / b c * d e ");
////////////////////////////////////////////////

String E(" ( ( ( ( Ax * b ) + (cd / e ) ) - f ) + g ) ;");
String F;
         
F = inToPrefix(E);

assert(F == "+ - + * Ax b / cd e f g");
//////////////////////////////////////////////////
        
String G(" ( ( ( ( ( ( c * b ) / ax ) + f ) - j ) + ( h * g ) ) - c ) ;");
String H;
         
H = inToPrefix(G);
         
assert(H == "- + - + / * c b ax f j * h g c");
 
std::cout << "Infix to Prefix Called!" << std::endl;
 }
         
         
         
         
         
         
