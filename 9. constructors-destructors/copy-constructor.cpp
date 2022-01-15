// CPP also us to delegate the constructors for initialization list.

#include <iostream>
using namespace std;

class Player {
private:
  string name;
  int health;
  int xp;

public:
  std::string getName() { return name; }
  int getHealth() { return health; }
  int getXp() { return xp; }

  // delegated constructor with default values <- very very efficient
  Player(std::string n = "None", int health_val = 0,
         int xp_val = 0); // This constructor will be called, when we creating
                          // objects with 0, 1, 2, 3 args.

  // COPY CONSTRUCTOR
  Player(const Player &source);

  // destructor
  ~Player() { cout << "Destructor called for " << name << endl; }
};

// delegated constructor with default values <- very very efficient
Player::Player(std::string n, int health_val, int xp_val)
    : name{n}, health{health_val}, xp{xp_val} {
  cout << "Three args constructor" << endl;
}

// Player::Player(const Player &source)
//     : name{source.name}, health{source.health}, xp{source.xp} {
//   cout << "Copy - Constructor called and made a copy of" << source.name <<
//   endl;
// }

// We can also simply write a above copy constructor like below
Player::Player(const Player &source)
    : Player{source.name, source.health, source.xp} {
  cout << "Copy - Constructor called and made a copy of" << source.name << endl;
}

void displayPlayer(
    Player p) { // Player p = new Player(sharan) OR Player p{sharan}
                // HERE: sharan is arg while calling
                // You can see, we have creating an local object(args) for
                // Player. But, we need to make a copy. Reason is, if we change
                // anything without making a copy, it will affects the real
                // object which is calling. Finally, In this line we are calling
                // copy constructor and Got a copied object. This object gets
                // deleted when this local scope ends.
                // This is shallow copy by the way.
  cout << "Name: " << p.getName() << endl;
  cout << "Health: " << p.getHealth() << endl;
  cout << "XP: " << p.getXp() << endl;
}

int main() {
  Player sharan;
  displayPlayer(sharan);

  Player sharan_copy{sharan}; // copy constructor called
  displayPlayer(sharan_copy);

  Player dhoni{"Dhoni"};
  Player raina{"Raina", 100, 100};
  return 0;
}