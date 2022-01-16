#include <iostream>
#include <string>

template <typename T> // template 1
T min(T a, T b) {
  return (a < b) ? a : b;
}

template <typename T1, typename T2> // template 2
void func(T1 a, T2 b) {
  std::cout << a << " " << b << std::endl;
}

struct Person { // you can create a class also.
  std::string name;
  int age;

  bool operator<(const Person &rhs) const { // operator overloading
    return this->age < rhs.age;
  }
};

std::ostream &operator<<(std::ostream &os, const Person &p) {
  os << p.name;
  return os;
}

int main() {
  std::cout << min(5, 1) << std::endl;
  std::cout << min<int>(5, 3) << std::endl;
  // std::cout << min(5, 1.0) << std::endl; // This is an error. Reason: we
  // declared one template so, it will accept one data-type.
  std::cout << min(5.4, 3.2) << std::endl;
  std::cout << min('A', 'Z') << std::endl;

  // If we don't make operator overloading (<) in class Person, the below will
  // throw an error.
  Person p1{"Sharan", 21};
  Person p2{"Dhoni", 40};
  Person p3 = min(p1, p2);
  std::cout << p3.name << " is younger" << std::endl;

  func(10, 20);
  func<int, int>(20, 10);
  func('A', 100);
  func(1000, "Test");
  func<int, double>(10, 10.9);

  // If we don't make operator overloading (<<) in class person, the below will
  // throw an error.
  func(p1, p2);

  return 0;
}