include <iostream>
#include <cassert>
#include "stack.hpp"
#include "../string/string.hpp"

int main()
{
  //TESTING A STACK OF INTEGERS
  {
    Stack<int> a;

    assert(a.isEmpty() == true);

    a.push(1);
    assert(a.isEmpty() == false);
    a.push(5);
    a.push(9);

    assert(a.isEmpty() == false);
    assert(a.isFull() == false);
  }

  {
    Stack<int> b;

    assert(b.isEmpty() == true);

    b.push(56);
    assert(b.isEmpty() == false);
    b.push(4);
    b.push(88);
    b.push(345);

    assert(b.isEmpty() == false);
    assert(b.isFull() == false);
  }

  //TESTING A STACK OF STRINGS
  {
  Stack<String> c;

  assert(c.isEmpty() == true);

  c.push("Happy");
   assert(c.isEmpty() == false);
  c.push("Camper");

  assert(c.isEmpty() == false);
  assert(c.isFull() == false);
  }

  {
    Stack<String> d;

    assert(d.isEmpty() == true);

    d.push("Great");
    assert(d.isEmpty() == false);
    d.push("fantastic");
    d.push("fabulous");
    d.push("perfect");

    assert(d.isEmpty() == false);
    assert(d.isFull() == false);
  }

  std::cout << "Push Function Called!" << std::endl;
}
