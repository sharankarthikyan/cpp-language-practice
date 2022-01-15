// Assignment is not initialization

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

// constructor using assignment
// Player::Player() {
//   name = "Sharan";
//   health = 100;
//   xp = 80;
// }

// Player::Player(std::string n) {
//   name = n;
//   health = 90;
//   xp = 100;
// }

// Player::Player(std::string n, int health_val, int xp_val) {
//   name = n;
//   health = health_val;
//   xp = xp_val;
// }

// Constructor using initialization list <- effiecient way initializing using
// constructor
Player::Player() : name{"Sharan"}, health{100}, xp{80} {}

Player::Player(std::string n) : name{n}, health{90}, xp{100} {}

Player::Player(std::string n, int health_val, int xp_val)
    : name{n}, health{health_val}, xp{xp_val} {}

int main() {
  Player sharan;
  Player dhoni{"Dhoni"};
  Player raina{"Raina", 100, 100};
  return 0;
}