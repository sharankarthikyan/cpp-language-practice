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

  // Overloading Constructor.
  Player();
  Player(std::string);
  Player(std::string, int, int);
};

// Constructor using initialization list <- effiecient way initializing using
// constructor
// Player::Player() : name{"Sharan"}, health{100}, xp{80} {}

// Player::Player(std::string n) : name{n}, health{90}, xp{100} {}

// Player::Player(std::string n, int health_val, int xp_val)
//     : name{n}, health{health_val}, xp{xp_val} {}

// Delegating the initialization list constructors <- removed duplicate codes in
// simple constructor using initialization list

// Delegating the intialization list constructor is very efficient way of
// constructor.
Player::Player() : Player("Sharan", 100, 80) {
  cout << "No args constructor" << endl;
}

Player::Player(std::string n) : Player(n, 90, 100) {
  cout << "One args constructor" << endl;
}

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