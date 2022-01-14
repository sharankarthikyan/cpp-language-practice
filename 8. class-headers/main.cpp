// complie multiple .cpp files: g++ -Wall -std=c++14 -g main.cpp Account.cpp
// Now, you got your object code run that alone.
// For me, a.out means `assembly output`. I execute this line ./a.out

#include "Account.h"
#include <iostream>

using namespace std;

int main() {
  Account sharan;
  sharan.setName("Sharan");
  sharan.setBalance(1000);

  if (sharan.deposit(100)) {
    cout << "Deposit OK" << endl;
  } else {
    cout << "Deposit Not Allowed" << endl;
  }

  if (sharan.withdraw(200)) {
    cout << "Withdraw OK" << endl;
  } else {
    cout << "Not sufficient money in your account" << endl;
  }

  if (sharan.withdraw(1000)) {
    cout << "Withdraw OK" << endl;
  } else {
    cout << "Not sufficient money in your account" << endl;
  }
  return 0;
}