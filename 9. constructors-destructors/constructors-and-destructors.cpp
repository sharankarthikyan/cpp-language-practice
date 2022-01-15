// If class doesn't have ANY constructor. Default constructor will be called and
// does nothing, Just create a object for that paticular class.

// You have created one constructor with one arg and trying to create one object
// with no arg, this will produce an error.

// EX: Account class have only one constructor with one arg.
// You are creating a object like this -> Account a; -OR- Account a = new
// Account; this will produce an error. Reason: You have manually created one
// constructor. So, default constructor will not be called. While you creating
// that object with no constructor. Compiler will search for no arg constructor
// and it is not found.

#include <iostream>
using namespace std;

class Player {
private:
  string name;
  int health;
  int xp;

public:
  void setName(std::string n) { name = n; }

  // Overloading Constructor.
  Player() { cout << "No arg constructor called" << endl; }

  Player(std::string name) { cout << "String arg constructor called" << endl; }

  Player(std::string name, int health, int xp) {
    cout << "Three arg constructor called" << endl;
  }

  ~Player() { cout << "Destructor called for " << name << endl; }
};

int main() {

  // creating Player object / instance
  {
    Player sharan; // No args constructor called on this line
    sharan.setName("Sharan");
  } // The destructor will be called if the scope of object ends.

  {
    Player dhoni; // No args constructor called on this line
    dhoni.setName("Dhoni");

    Player raina("Raina"); // String args constructor called on this line
    raina.setName("Raina");

    Player jadu("Jadu", 100, 100); // Three args constructor called on this line
    jadu.setName("Jadu");
  } // The destructor will be called if the scope of object ends. NOTE:
    // destructor called in descending manner. But, constructor is ascending.

  // creating Player object / instance in HEAP
  Player *enemy = new Player; // No args constructor called on this line
  enemy->setName("Enemy");

  Player *boss = new Player("Boss", 1000,
                            1000); // Three args constructor called on this line
  boss->setName("Boss");

  // If you comment the below line destructor will not be called. The reason is
  // those objects are in scope that pointer to obejct pointing to that address
  // in memory.
  delete enemy;
  delete boss;

  return 0;
}