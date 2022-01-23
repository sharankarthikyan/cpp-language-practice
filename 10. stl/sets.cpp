// set doesn't allow duplicate elements in a set.
#include <algorithm>
#include <iostream>
#include <set>

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

template <typename T> void display(const std::set<T> &s) {
  std::cout << "[ ";
  for (const auto ele : s) {
    std::cout << ele << " ";
  }
  std::cout << "]" << std::endl;
}

void test1() {
  // Sets: normally sets are ordered.
  std::cout << "Test1 =======================================" << std::endl;
  std::set<int> s1{1, 4, 3, 5, 2};
  display(s1);

  s1 = {1, 2, 3, 1, 1, 2, 2, 3, 3, 4, 5};
  display(s1); // sets doesn't allow duplicate values

  // we didn't mension the position of inserting an element, reason is: it is
  // inserted on orderly.
  s1.insert(0);
  s1.insert(10);
  display(s1);

  if (s1.count(10)) {
    std::cout << "10 is in the set." << std::endl;
  } else {
    std::cout << "10 is not in the set." << std::endl;
  }

  auto it = s1.find(5);
  if (it != s1.end()) {
    std::cout << "Found: " << *it << std::endl;
  }

  s1.clear();
  display(s1);
}

void test2() {
  std::cout << "Test2 =======================================" << std::endl;
  std::set<Person> squad{{"Sharan", 21}, {"Dhoni", 38}, {"Raina", 35}};
  display(squad); // NOTE: order of display! operator<

  squad.emplace("Jadu", 30); // NOTE: there is no emplace_front or emplace_back.
                             // Because, set insert orderly.
  display(squad);

  squad.emplace("Kohli", 30); // No -- 30 already exists
  display(squad);

  auto it = squad.find(Person{"Dhoni", 38});
  if (it != squad.end()) {
    squad.erase(it);
  }
  display(squad);

  it = squad.find(Person{"XXXX", 30}); // Will remove Jadu
                                       // uses operator<
  if (it != squad.end()) {
    squad.erase(it);
  }
  display(squad);
}

void test3() {
  std::cout << "Test2 =======================================" << std::endl;

  std::set<std::string> s{"A", "B", "C"};
  display(s);

  auto result = s.insert("D"); // this returns -> std::pair<iterator, bool>
  // The reason this type of return is, we can know the insertion is success or
  // not. Because sets didn't allow duplicate values.
  display(s);

  std::cout << std::boolalpha; // if you comment this `result.second` will comes
                               // with a int value 1 or 0. If you make this line
                               // uncomment, it comes like true or false.
  std::cout << "First: " << *(result.first) << std::endl;
  std::cout << "Second: " << result.second << std::endl;

  std::cout << std::endl;

  result = s.insert("A");
  display(s);

  std::cout << std::boolalpha;
  std::cout << "First: " << *(result.first) << std::endl;
  std::cout << "Second: " << result.second << std::endl;
}

int main() {
  // test1();
  // test2();
  test3();
  return 0;
}