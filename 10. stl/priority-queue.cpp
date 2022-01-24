#include <iostream>
#include <queue>

class Person {
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  std::string name;
  int age;

public:
  Person() : name{"Unknown"}, age{0} {}
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

template <typename T> void display(std::priority_queue<T> pq) {
  std::cout << "[ ";
  while (!pq.empty()) {
    T ele = pq.top();
    pq.pop();
    std::cout << ele << " ";
  }
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "Test1 =======================================" << std::endl;

  std::priority_queue<int> pq;
  for (int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7}) {
    pq.push(i);
  }
  display(pq);

  std::cout << "Size: " << pq.size() << std::endl;
  std::cout << "Top: " << pq.top()
            << std::endl; // it gives highest element in queue

  pq.pop();
  display(pq);
}

void test2() {
  std::cout << "Test2 =======================================" << std::endl;
  std::priority_queue<Person> pq;
  pq.push(Person{"A", 21});
  pq.push(Person{"B", 38});
  pq.push(Person{"c", 1});
  pq.push(Person{"D", 14});
  pq.push(Person{"E", 18});
  pq.push(Person{"F", 7});
  pq.push(Person{"G", 27});

  // the priority queue give priority to higher elements with the help of
  // operator<
  display(pq);
}

int main() {
  // test1();
  test2();
  return 0;
}