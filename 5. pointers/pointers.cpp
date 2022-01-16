#include <iostream>
using namespace std;

int main() {
  int *a;
  char *b;
  float *c;
  double *d;

  long double val = 23123;
  long double *e = &val;
  cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << " " << sizeof(d)
       << " " << sizeof(e)
       << endl; // sizeof address present inside the pointer.
  cout << sizeof(&a) << " " << sizeof(&b) << " " << sizeof(&c) << " "
       << sizeof(&d) << " " << sizeof(&e)
       << endl; // sizeof the address of the pointer
  cout << sizeof(*a) << " " << sizeof(*b) << " " << sizeof(*c) << " "
       << sizeof(*d) << " " << sizeof(*e)
       << endl; // sizeof the data present inside that pointer holds address.
  return 0;
}