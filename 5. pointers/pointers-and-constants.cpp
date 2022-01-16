#include <iostream>
using namespace std;

int main() {
  // pointer to constant integer.
  int const a = 10;
  int const *p1 = &a; // Keyword can be like this: const int*
  // *p1 = 11;  // Error, pointer `p` is pointing to the same address `a` is
  // pointing to. So, we can't able to change to value of pointer that holds
  // const integer.
  cout << p1 << endl;
  const int b = 20;
  p1 =
      &b; // No Error, we can able to change to pointer's address. Because
          // pointer is not constant. The pointer is points to is a const value.
  cout << p1 << endl;

  // constant pointer to integer.
  int c = 30;
  int *const p2 = &c;
  int d = 40;
  // p2 = &d; // Error, here pointer is constant. The value, pointer is to be
  // store is not a constant. So, if change address of pointer, it thows error.
  // We can change the value that the pointer is pointing to.
  *p2 = 60; // No Error

  // Const pointer to const integer.
  int const e = 10;
  int const *const p3 = &e; // Keyword can be like this: const int *const
  int const f = 100;
  // p3 = &f; // Error.
  // *p3 = 200; // Error.
  // Both pointer and pointer that holds address of another variable, both are
  // const. So, we can't change the either of the values.

  return 0;
}