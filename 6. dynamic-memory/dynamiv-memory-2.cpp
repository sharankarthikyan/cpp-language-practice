// In this program, we can clearly understand the heap memory allocated for
// programmers.

// Run the program, you will automatically receive a address of one pointer
// and give the size as `0` in how many temps. Now, you will receive the same
// address, which you received before.

// The reason is we just deleted the first pointer and second pointer also
// starts with that free address.

#include <iostream>
using namespace std;

int main() {

  int scores[3]{10, 20, 30};
  int *scores_ptr{scores};

  cout << "Array Value at scores using subscript notation \n";
  cout << scores[0] << endl; // scores address + 0 bytes
  cout << scores[1] << endl; // scores address + 4 bytes
  cout << scores[2] << endl; // scores address + 8 bytes

  cout << "Pointer Value at scores_ptr using subscript notation \n";
  cout << scores_ptr[0]
       << endl; // scores_ptr pointes to scores address + 0 bytes
  cout << scores_ptr[1]
       << endl; // scores_ptr pointes to scores address + 4 bytes
  cout << scores_ptr[2]
       << endl; // scores_ptr pointes to scores address + 8 bytes

  cout << "Array Value at scores using offset notation \n";
  cout << *(scores + 0) << endl; // scores address + 0 bytes
  cout << *(scores + 1) << endl; // scores address + 4 bytes
  cout << *(scores + 2) << endl; // scores address + 8 bytes

  cout << "Pointer Value at scores_ptr using offset notation \n";
  cout << *(scores_ptr + 0)
       << endl; // scores_ptr pointes to scores address + 0 bytes
  cout << *(scores_ptr + 0)
       << endl; // scores_ptr pointes to scores address + 4 bytes
  cout << *(scores_ptr + 0)
       << endl; // scores_ptr pointes to scores address + 8 bytes

  return 0;
}