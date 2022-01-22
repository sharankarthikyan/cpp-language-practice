#include <algorithm>
#include <cctype>
#include <iostream>
#include <list>
#include <vector>

class Person {
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

void find_test() {
  std::list<Person> players{{"Sharan", 21}, {"Dhoni", 39}, {"Raina", 35}};

  auto loc = std::find(players.begin(), players.end(), Person{"Jadu", 10});
  if (loc != players.end()) {
    std::cout << "Found Jadu" << std::endl;
  } else {
    std::cout << "Not Found Jadu" << std::endl;
  }
}

void count_test() {
  std::cout << "=================================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 1, 7, 1, 1};
  int num = std::count(vec.begin(), vec.end(),
                       1); // counting how many times 1 is appearing.

  std::cout << num << " occurrences found" << std::endl;
}

void count_if_test() {
  std::cout << "=================================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5, 100, 200};

  int num = std::count_if(vec.begin(), vec.end(), [](int x) {
    return x % 2 == 0;
  }); // This is lambda function : [](int x) { return x % 2 == 0; }
  std::cout << num << " even numbers found" << std::endl;

  num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; });
  std::cout << num << " odd numbers found" << std::endl;
}

void replace_test() {
  std::cout << "=================================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
  for (auto i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::replace(vec.begin(), vec.end(), 1, 9);
  for (auto i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void all_of_test() {
  std::cout << "=================================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 20, 100};

  if (std::all_of(vec.begin(), vec.end(), [](int x) {
        return x > 10;
      })) { // return true if all the elements greater than 10.
    std::cout << "All elements are greated than 10" << std::endl;
  } else {
    std::cout << "All elements are not greated than 10" << std::endl;
  }
}

void string_transform_test() {
  std::cout << "=================================" << std::endl;
  std::string str{"hello there"};

  std::cout << "Before transform " << str << std::endl;
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  std::cout << "After transform " << str << std::endl;
}

int main() {
  find_test();
  count_test();
  count_if_test();
  replace_test();
  all_of_test();
  string_transform_test();
  return 0;
}