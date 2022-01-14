#include <iostream>
#include <vector>
using namespace std;

class Player {

public:
    // Attributes
    string name;
    int health;
    int xp;

    // Methods
    void talk(string text_to_say) {
        cout<<name<<" says "<<text_to_say<<endl;
    }

    bool is_dead(){
        return health <= 0 ? true : false;
    }
};


class Account {

public:
    // attributes
    string name;
    double balance;

    // methods
    bool deposit(double); // declared. NOT defined.
    bool withdraw(double);
};

int main() {
    // creating instance of a class Player.
    Player sharan;
    Player dhoni; // dhoni is Player Object.

    // creating instance of a class Player in a HEAP
    Player *sony {nullptr}; // pointer to Player object. Like pointer to integer.
    sony = new Player();

    Player *ross = new Player(); // ross is PONINTER TO PLAYER OBJECT. NOTE: NOT A PLAYER OBJECT.

    // array of Players
    Player team[] {sharan, dhoni};

    // vector of Players
    vector<Player> squad {sharan};
    squad.push_back(dhoni);

    // assigning values to the Player objects / instances.
    sharan.name = "Sharan";
    sharan.health = 100;
    sharan.xp = 100;
    cout<<sharan.name<<" "<<sharan.health<<" "<<sharan.xp<<endl;

    // assigning values to the Player objects / instances created in HEAP.
    (*sony).name = "Sony"; // Here, () has higher precedence. So, first we dereference the object and we accessing the members stored in that object-pointer's holds address.
    // accessing using member of pointer operator / arrow operator.
    sony->health = 100;
    sony->xp = 100;
    cout<<(*sony).name<<" "<<sony->health<<" "<<sony->xp<<endl;

    // accessing methods in a class using objects.
    sharan.talk("Hi, there!!");

    // accessing methods in a class using pointer to object.
    (*sony).talk("Hehehe!!!");
    sony->talk("Blah blah...");

    // clearing the space allocated in the heap. Some compiler will automatically do this.
    delete sony;
    delete ross;

    return 0;
}