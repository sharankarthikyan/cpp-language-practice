#include <algorithm>
#include <iostream>
#include <vector>

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

void display2(const std::vector<int>
                  &vec) { // lambda expression to display vector elements
  std::cout << "[ ";
  std::for_each(vec.begin(), vec.end(), [](int x) { std::cout << x << " "; });
  std::cout << "]" << std::endl;
}

// template function to display any vector
template <typename T> void display(const std::vector<T> &vec) {
  std::cout << "[ ";
  for (const auto ele : vec) {
    std::cout << ele << " ";
  }
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "Test1 ====================================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);

  vec = {2, 3, 4, 5};
  display2(vec);

  std::vector<int> vec1(10, 100); // ten 100s in the vector
  display(vec1);
}

void test2() {
  std::cout << "Test2 ====================================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5};

  display(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity() << std::endl;

  vec.push_back(6);
  display(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity()
            << std::endl; // capacity become 10. assume we first allowcate 1000
                          // int values and you try to add 1 value to that
                          // vector. Now the vector capacity is 2000. But, 999
                          // int is wasted. So, the below shrink_to_fit came

  vec.shrink_to_fit(); // C++11 // it will allow us to fit the capacity to size
                       // of vector.
  display(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity()
            << std::endl; // now capacity is 6.

  vec.reserve(100); // we can allocate the capacity
  display(vec);
  std::cout << "vec size: " << vec.size() << std::endl;
  std::cout << "vec max size: " << vec.max_size() << std::endl;
  std::cout << "vec capacity: " << vec.capacity()
            << std::endl; // now capacity is 100
}

void test3() {
  std::cout << "Test3 ====================================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);

  vec[0] = 100;
  vec.at(1) = 200; // efficient
  display(vec);
}

void test4() {
  std::cout << "Test4 ====================================" << std::endl;
  std::vector<Person> squad;

  Person sharan{"Sharan", 21};
  display(squad);

  squad.push_back(sharan);
  display(squad);

  squad.push_back(Person{"Dhoni", 38});
  display(squad);

  squad.emplace_back(
      "Raina",
      35); // Efficient than push back. so, use emplace-back. It is actually
           // call the constructor by itself without mentioning
  display(squad);
}

void test5() {
  std::cout << "Test5 ====================================" << std::endl;
  std::vector<Person> squad{{"Sharan", 21}, {"Dhoni", 38}, {"Raina", 35}};
  display(squad);

  std::cout << "Front: " << squad.front() << std::endl;
  std::cout << "Back: " << squad.back() << std::endl;

  squad.pop_back();
  display(squad);
}

void test6() {
  std::cout << "Test6 ====================================" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5};
  display(vec);

  vec.clear();
  display(vec);

  vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  display(vec);
  vec.erase(vec.begin(), vec.begin() + 2);
  display(vec);

  vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // erase all even numbers
  auto it = vec.begin();
  while (it != vec.end()) {
    if (*it % 2 == 0) {
      vec.erase(it);
    } else {
      it++;
    }
  }
  display(vec);
}

void test7() {
  std::cout << "Test7 ====================================" << std::endl;
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{10, 20, 30, 40, 50};

  display(vec1);
  display(vec2);
  std::cout << std::endl;

  vec1.swap(vec2);
  display(vec1);
  display(vec2);
}

void test8() {
  std::cout << "Test8 ====================================" << std::endl;
  std::vector<int> vec1{1, 21, 3, 40, 12};

  display(vec1);
  std::sort(vec1.begin(), vec1.end());
  display(vec1);
}

void test9() {
  std::cout << "Test9 ====================================" << std::endl;
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{10, 20};

  display(vec1);
  display(vec2);
  std::cout << std::endl;

  std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  // copy if
  vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vec2 = {10, 20};
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
               [](int x) { return x % 2 == 0; });
  display(vec1);
  display(vec2);
  std::cout << std::endl;
}

void test10() {
  std::cout << "Test10 ====================================" << std::endl;
  std::vector<int> vec1{1, 2, 3, 4, 5};
  std::vector<int> vec2{10, 20, 30, 40, 50};
  std::vector<int> vec3;

  // 1*10, 2*20, 3*30, 4*40, 5*50 and store the result in vec3
  std::transform(vec1.begin(), vec1.end(), vec2.begin(),
                 std::back_inserter(vec3), [](int x, int y) { return x * y; });

  display(vec3);
}

void test11() {
  std::cout << "Test11 ====================================" << std::endl;
  std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2{100, 200, 300, 400};
  display(vec1);
  display(vec2);
  std::cout << std::endl;

  auto it = std::find(vec1.begin(), vec1.end(), 5);
  if (it != vec1.end()) {
    std::cout << "Inserting..." << std::endl;
    vec1.insert(it, vec2.begin(), vec2.end());
  } else {
    std::cout << "Sorry, 5 not found" << std::endl;
  }
  display(vec1);
}

int main() {
  // test1();
  // test2();
  // test3();
  // test4();
  // test5();
  // test6();
  // test7();
  // test8();
  // test9();
  // test10();
  test11();
  return 0;
}