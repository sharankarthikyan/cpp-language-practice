// Shallow copy - only the pointer is copied - not what is pointing to!
// Problem: source and newly created object BOTH point to the SAME data area.

#include <iostream>
using namespace std;

class Shallow {
private:
  int *data;

public:
  void setDataValue(int d) { *data = d; }
  int getDataValue() { return *data; }

  Shallow(int d);

  // COPY CONSTRUCTOR
  Shallow(const Shallow &source);

  // destructor
  ~Shallow();
};

Shallow::Shallow(int d) {
  data = new int;
  *data = d;
}

Shallow::Shallow(const Shallow &source) : data{source.data} {
  cout << "Copy Constructor - Shallow copy" << endl;
}

Shallow::~Shallow() {
  delete data;
  cout << "Destructor freeing data" << endl;
}

void displayShallow(Shallow s) { cout << s.getDataValue() << endl; }

int main() { // This shallow copy will cause an error.
  Shallow obj1{100};
  displayShallow(obj1);

  Shallow obj2{obj1};
  cout << &obj1 << " " << &obj2 << endl;
  obj2.setDataValue(1000);

  return 0;
}