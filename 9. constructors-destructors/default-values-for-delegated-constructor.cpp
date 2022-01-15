// CPP also us to delegate the constructors for initialization list.

#include <iostream>
using namespace std;

class Player {
private:
  string name;
  int health;
  int xp;

public:
  void setName(std::string n) { name = n; }

  // delegated constructor with default values <- very very efficient
  Player(std::string n = "None", int health_val = 0,
         int xp_val = 0); // This constructor will be called, when we creating
                          // objects with 0, 1, 2, 3 args.
};

// Delegating the initialization list constructors <- removed duplicate codes in
// simple constructor using initialization list

// Delegating the intialization list constructor is very efficient way of
// constructor.
// Player::Player() : Player("Sharan", 100, 80) {
//   cout << "No args constructor" << endl;
// }

// Player::Player(std::string n) : Player(n, 90, 100) {
//   cout << "One args constructor" << endl;
// }

// Player::Player(std::string n, int health_val, int xp_val)
//     : name{n}, health{health_val}, xp{xp_val} {
//   cout << "Three args constructor" << endl;
// }

// delegated constructor with default values <- very very efficient
Player::Player(std::string n, int health_val, int xp_val)
    : name{n}, health{health_val}, xp{xp_val} {
  cout << "Three args constructor" << endl;
}

int main() {
  Player sharan;
  Player dhoni{"Dhoni"};
  Player raina{"Raina", 100, 100};
  return 0;
}