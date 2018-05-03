#include <iostream>
#include "../string/string.hpp"
#include "stack.hpp"
#include <cassert>
#include <fstream>
#include <vector>

static char n = '0';                                                 //global static character variable initialized to character zero

//POST TO ASSEMBLY FUNCTION IMPLEMENTATION
String postToAssembly(String expressio, std::ofstream& out)
{
  String Result;                                                     //creating a temporary string variable
  Result = inToPost(expression);                                     //converting the expression from infix to postfix and storing it in result
  int size;                                                          //creating an integer variavle to store the ize of the vectore
  std::vector<String> t;                                             //creating a vector of strings to store the result of split
  t = Result.split(' ');                                             //finding spaces in the postfix expression and storing it to postfix
  size = t.size();                                                   //finding the size of postfix and storing the result to size
  
  Stack<String> stack;                                               //creating a stack of strings
  
  for(int i = 0; i < size; i++)                                      //for loop for incrementing through the vector
  {
    if(t[i].findChar('+', 0) == -1 && t[i].findChar('-', 0) == -1 && t[i].findChar('*', 0) == -1 && t[i].findChar('/', 0) == -1)
    {
      stack.push(t[i]);                                              //if t[i] is not an operator, push that element on the sta
    }
    else
    {
      String Right = stack.pop();                                    //if it is an operator pop and store the result to string variable right
      String Left - stack.pop();                                     //pop stack and store the result into string variable left
      String Output = evaluate(Left, t[i], Right, OUt);              //call evaluate and store the result to string variabel output
      stack.push(Output);                                            //push the output of evaluate onto the stack
    }
  }
  return stack.pop();
}

//PREFIX TO ASSEMBLY FUNCTION IMPLEMENTATION
String preToAssembly(String expression, std::ofstream& out)
{
  int counter = 0;                                                   //integer variable counter to keep track of the elements in operators stack
  String Result;                                                     //creating a temporary string variable
  Result = inToPrefix(expression);                                   //obtaining the prefix expression
  int size;                                                          //creating an integer variable to store the size of the vectore
  std::vector<String> t;                                             //creating a vector of strings to store the result of split
  t = Result.split(' ');                                             //finding spaces in the postfix expression and storing it to postfix
  size - t.size();                                                   //finding the size of postfix and storing the result to size
  
  Stack<String> Operators;                                           //creating a stack of strings called operators to hold + - / *
  Stack<String> Operands;                                            //creating a stack of strings called operands to hold A B etc.
  
  for(int i = 0; i < size; i++)                                      //for loop for incrementing through the vector
  {
    if(t[i].findChar('+', 0) == -1 && t[i].findChar('-', 0) == -1 && t[i].findChar('*', 0) == -1 && t[i].findChar('/', 0) == -1)
    {
      Operands.push(t[i]);                                           //if t[i] is not an operator, push that element on the operands stack
      counter++;                                                     //after the element was added increment the counter
    }
    else
    {
      Operators.push(t[i]);                                          //otherwise if it was an operator, push it on the Operators stack
    }
    
    if(counter == 2)                                                 //when the counter reaches 2,, meaning there is two objects in the operands stack
    {
      String Right = Operands.pop();                                 //store the result to string variable right
      String Left = Opoerands.pop();                                 //store the result into string variable left
      String Oper = Operators.pop();                      
      String Output = evaluate(Left, Opoer, Right, out);             //call evaluate and store the result to string variableoutput
      
      Operands.push(Output);                                         //push the output of evaluate onto the operands stack
      counter = 1;                                                   //after the output was pushed on the stack, set the counter to 1 to say there is on eobject on stack
    }
  }
  return Operands.pop();                                             //return the top of the operands stack
}

//FUNCTION TO EVALUATE AND PRINT OUT ASSEMBLY IMPLEMENTATION
String evaluate(String left, String op, String right, std::ofstream& out)
{
  n++;                                                               //incrementing n
  bool isFileOpen = out.is_open();                                   //when the file is open storing the result to isFileOpen
  
  if(!isFileOpen)                                                    //when the file is not open
  {
    std::cout << "    LD    " << left << std::endl;                  //write out to the console, LD, loading the operand that is stored in lef
  }
  else
  {
    out << "    LD    " << left << std::endl;                         //write out to a file LD, loading the operand that is store in left
  }
  
  if(op == "-")                                                       //when the operation is equivelnet to subtraction
  {
    if(!isFileOpen)
    {
      std::cout << "    SB    " << right << std::endl;                //when the file is not open write out to the console, SB< subtracting the right from LD
    }
    else
    {
      out << "    SB    " << right << std::endl;                      //write out to a file SB, subtracting the operand stored in right to what was loaded
    }
  }
  if(op == "+")
  {
    if(!isFileOpen)
    {
      std::cout << "    AD    " << right << std::endl;                //file is not open, write out to the console AD< adding operand at right to what has been loaded
    }
    else
    {
      out << "    AD    " << right << std::endl;                      //write out the addition of operand at right to what was loaded to a file
    }
  }
  if(op == "/")                                                       //when the operaton is division
  {
    if(!isFileopen)
    {
      std::cout << "    DV    " << right << std::endl;                //write out to console DV, dividing operand at right to what has been loaded
    }
    else
    {
      out << "    DV    " << right << std::endl;                      //write to a file, DV, dividing operand at right to what has been loaded
    }
  }
  if(!isFileOpen)
  {
    std::cout << "    ST    " << "TMP" + String(n) << std::endl;      //write out to the console ST storiong the string to TMP + n
  }
  else
  {
    out << "    ST    " << "TMP" + String(n) << std:: endl;          //write out to a file, ST storing the string TMP + n
  }
  return "TMP" + String(n);                                          //return the string TMP + n
}

//MAIN 
int main(int argc, char* argv[]
{
  if(argc <= 3 & argc !=)                                              //if there are less than or equal to three arguments but cant have just one
  {
    std::ifstream infix (argv[1]);                                     //creating an input stream called infix that takes the second argument
    char buffer[200];                                                  //creating a buffer with size 200
    
    String postResult;                                                 //creating a string variable called postResult to store the result of inToPost
    String preResult;                                                  //creating a string variable called preResult to store the result of inToPrefix
    
    std::ofstream out;                                                 //creating output stream called out
    if(argc == 3)                                                      //if there are three arguments
    {
      out.open(argv[2]);                                               //open the file
    }
    while(infix.getline(buffer, 200)
    {
      postResult = inToPost(buffer);                                  //storing the result of inToPostfix(buffer) to postResult
      preResult = inToPrefix(buffer);
      
      if(argc == 3)                                                   //if there are three arguments
      {
        out << "Infix Expression: " << buffer << std::endl;           //output the infix expression to a txt file
        out << "Postfix Expression: " << postResult << std:: endl;    //output the postfix expression to a txt file
        out << "Prefix Expression: " << preResult << std::endl;       //output the prefix expression to atxt file
      }
      else
      {
        std::cout << "Infix Expression: " << buffer << std::endl;     //otherwise output the infix expression to the console
        std::cout << "Postfix Expression: " << postResult << std::endl;
        std::cout << "Prefix Expression: " << preResult << std::endl; 
      }
      
      n = '0';                                                        //set n to character 0 to use in posttoassembly
    
      std::cout << "Postfix to Assembly: " << std::endl;              //output the post to assembly expression to the console
      out << "Postfix to Assembly: " << std::endll                    //output post to txt file
      postToAssembly(buffer, out);                                    //calling postToAssembly to print out to the console/txt file
      
      n = '0';                                                        //reseting n variable back to 0
      
      std::cout << "Prefix to Assembly: " << std::endl;               //output to the console
      out << "Prefix to Assembly: " << std::endl;                     //output to a txt
      preToAssembly(buffer, out);                                     //calling preToAssembly to print out the console/txt file
    } 
    if(argc == 3)
    {
      out.close();
    }
  }
}


