#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account {
private:
  std::string name;
  double balance;

public:
  void setBalance(double bal) { balance = bal; }
  double getBalance() { return balance; }

  void setName(std::string n);
  std::string getName();

  bool deposit(double amount);
  bool withdraw(double amount);
};

#endif