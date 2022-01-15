// DEEP - created new storage and copies the value

#include <iostream>
using namespace std;

class Deep {
private:
  int *data;

public:
  void setDataValue(int d) { *data = d; }
  int getDataValue() { return *data; }

  Deep(int d);

  // COPY CONSTRUCTOR
  Deep(const Deep &source);

  // destructor
  ~Deep();
};

Deep::Deep(int d) {
  data = new int;
  *data = d;
}

Deep::Deep(const Deep &source) { // HERE: we are deep constructing
  data = new int;
  *data = *(source.data);
  cout << "Copy Constructor - Deep copy" << endl;
}

Deep::~Deep() {
  delete data;
  cout << "Destructor freeing data" << endl;
}

void displayDeep(Deep s) { cout << s.getDataValue() << endl; }

int main() {
  Deep obj1{100};
  displayDeep(obj1);

  Deep obj2{obj1};
  obj2.setDataValue(1000);

  return 0;
}