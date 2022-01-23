// list is doubly linked list
// forward list is singly linked list. In this, back(), size() are not
// available.

#include <algorithm>
#include <iostream>
#include <iterator> //for std::advance
#include <list>

class Person {
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  std::string name;
  int age;

public:
  Person() = default;
  Person(std::string name, int age) : name{name}, age{age} {}
  bool operator<(const Person &rhs) const { return this->age < rhs.age; }
  bool operator==(const Person &rhs) const {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name << ":" << p.age;
  return os;
}

template <typename T> void display(const std::list<T> &li) {
  std::cout << "[ ";
  for (const auto ele : li) {
    std::cout << ele << " ";
  }
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "Test1 ====================================" << std::endl;

  std::list<int> li{1, 2, 3, 4, 5};
  display(li);

  std::list<std::string> li2;
  li2.push_back("back");
  li2.push_front("front");
  display(li2);

  std::list<int> li3;
  li3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(li3);

  std::list<int> li4(10, 100);
  display(li4);
}

void test2() {
  std::cout << "Test2 ====================================" << std::endl;

  std::list<int> li{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(li);

  std::cout << "Size: " << li.size() << std::endl;

  std::cout << "Front: " << li.front() << std::endl;
  std::cout << "Back: " << li.back() << std::endl;

  li.clear();
  display(li);

  std::cout << "Size: " << li.size() << std::endl;
}

void test3() {
  std::cout << "Test3 ====================================" << std::endl;

  std::list<int> li{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(li);

  li.resize(5);
  display(li);

  li.resize(10);
  display(li);

  std::list<Person> squad;
  squad.resize(5); // uses person default constructor.
  display(squad);
}

void test4() {
  std::cout << "Test4 ====================================" << std::endl;

  std::list<int> li{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(li);

  auto itr = std::find(li.begin(), li.end(), 5);
  if (itr != li.end()) {
    li.insert(itr, 100);
  }
  display(li);

  std::list<int> li2{1000, 2000, 3000};
  li.insert(itr, li2.begin(), li2.end());
  display(li);

  std::cout << *itr << std::endl; // value at this itr is 5.
  std::advance(itr, -4);          // point to the 100
  std::cout << *itr << std::endl;

  li.erase(itr);
  display(li);
}

void test5() {
  std::cout << "Test5 ====================================" << std::endl;

  std::list<Person> squad{{"Sharan", 21}, {"Dhoni", 38}, {"Raina", 35}};
  display(squad);

  std::string name;
  int age{};
  std::cout << "Enter name of the next person in a squad: ";
  getline(std::cin, name);
  std::cout << "Enter their age: ";
  std::cin >> age;

  squad.emplace_back(name, age);
  display(squad);

  auto it = std::find(squad.begin(), squad.end(), Person{"Raina", 35});
  if (it != squad.end()) {
    squad.emplace(it, "Jadu", 30);
  }
  display(squad);
}

int main() {
  // test1();
  // test2();
  // test3();
  // test4();
  test5();
  return 0;
}