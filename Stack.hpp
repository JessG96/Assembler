#include <iostream>
#include <cassert>
#include "../string/string.hpp"
#include <vector>

#ifndef STACK_H
#define STACK_H

template <typename T>
class Node
{
public:
  Node() :next (0) {};
  Node(const T& x) :noseValue(x), next(0) {};
  T nodeValue;
  Node <T>* next;
};
 
template <typename T>
class Stack
{
private:
 
  //pointer to top of stack
  Node<T>* tos;
  
public:

  //default constructor
  Stack() :tos(0) {};
  
  //copy constructor
  Stack(const Stack<T>&);
  
  //assignment operator
  Stack& operator=(Stack <T>);
  
  //destructor
  ~Stack();
  
  //constant time swap function
  void swap(Stack <T>&);
  
  //move constructor
  Stack(Stack&&);
  
  //empty function
  bool isEmpty() const {return tos == 0;}
  
  //full function
  bool isFull() const;
  
  //function for removing an element
  T pop();
  
  //function for adding an element to stack 
  void push(const T&);
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//IF FULL FUNCTION IMPLEMENTATION
template <typename T>

bool Stack<T>::isFull()const
{
  Node<T>* temp = new (std::nothrow) Node<T>;                    //creating a new node object
  if (!temp)                                                     //if not temp
    { 
      return true;                                               //if condition is true, return true
    } 
  else
    {
      delete temp;                                               //else if the condition is false delete temp
    }
  return false;                                                  //return false once out of the if/else statment
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//DESTRUCTOR IMPLEMENTATION
template <typename T>

Stack<T>::~Stack()
{
  Node<T>* temp;                                                 //creating a temporary node object
  while(tos != 0)                                                //while the top of stack is not null
    {
      temp = tos;                                                //when the condition of the while loop is true assign the top of stack to the temporary object
      tos = tos -> next;                                         //then have the top of stack point to the next node and assign it to top of stack
      delete temp;                                               //once through the while loop, delete the temporary object
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//COPY CONSTRUCTOR IMPLEMENTATION
template <typename T>

Stack<T>::Stack(cosnt Stack<T>& rhs)
{
  Node<T>* bottom;                                               //creating a new object of node called bottom
  Node<T>* temp = rhs.tos;                                       //creating a new object of node
  
  tos = 0;                                                       //setting top of stack to null/0
  while (temp != 0)                                              //while the top of stack is not a null
    {
      if (tos == 0)                                              //if top of stack is equivelant to zero
        {
          tos = new Node<T> (temp -> nodeValue);                 //creating a new object that points the temporary object to the nodeValue and assigns it to tos
          bottom = tos;                                          //top of stack is then assigned to the object bottom
        }
      else
        {
          bottom -> next = new Node<T> (temp -> nodeValue);      //create a new node that has temp point to nodeValue and assign it to bottom that points to the next node
          bottom = bottom -> next;                               //have bottom point to the next node/element and assign it to bottom
        }
      temp = temp -> next;                                       //pointing the temporary object to the next node and assigning it to temp
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//CONSTANT TIME SWAP FUNCTION IMPLEMENTATION  
template <typename T>

void Stack<T>::swap(Stack<T>& rhs)
{
  Node<T>* temp;                                                 //creating a temporary node object
  temp = tos;                                                    //assigning top of stack to the temporary object
  tos = rhs.tos;                                                 //taking the right handside top of stack and assigning it to the left hand side of stack (tos)
  rhs.tos = temp;                                                //assigning the temporary object value to the right hand side top of stack
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//ASSIGNMENT OPERATOR IMPLEMENTATION
template <typename T>

Stack<T>& Stack<T>::operator=(Stack<T> rhs)
{
  swap(rhs);                                                     //swapping the right handside with the left hand side by calling the swap function
  return *this;                                                  //returning the left handside, *this
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//MOVE ASSIGNMENT OPERATOR IMPLEMENTATION
template <typename T>

Stack<T>& Stack<T>::operator=(Stack<T>&& rhs)
{
  tos = rhs.tos;                                                 //taking the right handside top of sack and assigning it to the left handside top of stack (tos)
  rhs.tos = 0;                                                   //then passing the right handside top of stack to point to null
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//POP FUNCTION IMPLEMENTATION
template <typename T>

Stack<T>::pop()
{
  assert(tos != 0);                                              //determines that the top of stack is not a null
  T result = tos -> nodeValue;                                   //if tos is not a null, tos points to nodeValue and assigns it to result
  Node<T>* temp = tos;                                           //assigning the top of stack to a newly created node object called temp
  delete temp;                                                   //pointing top of stack to the next node and assigning it to the top of stack
  return result;                                                 //return the result of pop
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//PUSH FUNCTION IMPLEMENTATION
template <typename T>

void Stack<T>::push(const T& newItem)
{
  assert(!isFull());                                             //check to make sure that the stack is not full
  Node<T>* temp = new Node<T> (newItem);                         //when the stack is not full, create a new node temporary object and assign it to a new node data
  temp -> next = tos;                                            //assign top of stack to the next node that temp points to 
  tos = temp;                                                    //then assign temp to the top of stack
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//MOVE FUNCTION IMPLEMENTATION
template <typename T>

Stack<T>::Stack(Stack<T>&& rhs)
{
  tos = rhs.tos;                                                 //take whatever is in the right handside top of stack and assign it to top of stack
  rhs.tos = 0;                                                   //then assign the right handside top of stack to point to a null 
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//INFIX TO POSTFIX FREE FUNCTION IMPLEMENTATION

String inToPost(String expression)
{
  int size;                                                      //creating an integer variable called size to store the size of the vector
  std::vector<String> infix;                                     //creating a vector of strings called infix to use too add strings to the stack
  infix = expression.split('  ');                                //using the split function to find spaces in the string object called expression that is passed in
  sixe = infix.size();
  
  Stack<String> stack;                                           //creating a stack of strings
  for (int i = 0; i < size; i++)                                 //for loop to increment through infix, using size to limit the vector
  {
    if(infix[i].findChar(';', 0) != -1)                          //if the element of infix at index i is a semi-colon
    {
      break;                                                     //when condition is false break
    }
    if(infix[i].findChar(')', 0) != -1)                          //if the element of infix at index i is not closing parenthese
    {
      String right = stack.pop();                                //creating a string object called right and storing the first element from the stack
      String oper = stack.pop();                                 //creating a string object called oper and storing the second element from the stack
      String left = stack.pop();                                 //creating a string object called left and stroing the thrid element from the stack
      String result = left + " " + right + " " + oper;           //creating a string object called result andstoring left + space + right + space + oper in it
      stack.push(result);                                        //pushing the result onto stack 
    }
    else if((infix[i] != "(")                                    //if infix does not equal a beginning parenthese
    {
      stack.push(infix[i]);                                      //when condition is true, push the element at index i from vector infix to the stack 
    }
  }
return stack.pop();                                              //return the element on the stack
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//INFIX TO PREFIX FREE FUNCTION IMPLEMENTATION *CHALLENGE*

String inToPrefix(String expression)
{
  int size;
  std::vector<String> infix;
  
  infix = expression.split(' ');
  size = infix.size();
  
  Stack<String> stack;
  for(int i = 0; i < size; i++)
  {
    if(infix[i].findChar(';', 0) != -1)
    {
      break;
    }
    else if((infix[i] != "("))
    {
      stack.push(infix[i]);
    }
  }
 return stack.pop();
}

#endif
