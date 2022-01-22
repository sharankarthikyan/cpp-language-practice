#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

void display(
    const std::vector<int> &vec) { // display any vector using range based loop
  std::cout << "[ ";

  for (auto const i : vec) {
    std::cout << i << " ";
  }

  std::cout << "]" << std::endl;
}

void test1(std::vector<int> const &v) {
  std::cout << "=================================" << std::endl;

  // std::cout << v[0]
  //           << std::endl; // you can also get element values using indices.

  auto it = v.begin(); // `it` is in index 0.
  std::cout << *it << std::endl;
  it++;
  std::cout << *it << std::endl;
  it++;
  std::cout << *it << std::endl;

  it = v.end() - 1; // `it` is in index n - 1
  std::cout << *it << std::endl;
}

void test2() { // display all elements using iterators
  std::cout << "=================================" << std::endl;
  std::vector<int> num1{1, 2, 3, 4, 5};

  std::vector<int>::iterator itr = num1.begin();
  while (itr != num1.end()) {
    std::cout << *itr << std::endl;
    itr++;
  }

  itr = num1.begin();
  while (itr != num1.end()) { // changing all elements to 0.
    *itr = 0;
    itr++;
  }

  display(num1);
}

void test3() { // display all elements using const iterators
  std::cout << "=================================" << std::endl;
  std::vector<int> num1{1, 2, 3, 4, 5};

  std::vector<int>::const_iterator itr = num1.begin(); // using  const iterator.
  // The above and below lines were doing the same.
  // auto itr = num1.cbegin(); // using const begin

  while (itr != num1.end()) {
    std::cout << *itr << std::endl;
    itr++;
  }

  itr = num1.begin();
  while (itr != num1.end()) { // changing all elements to 0.
    // *itr = 0; // compiler error - READ only
    itr++;
  }
}

void test4() { // display all elements reverse using iterators
  std::cout << "=================================" << std::endl;
  std::vector<int> num1{1, 2, 3, 4, 5};

  auto itr = num1.rbegin(); // starts at the last index

  while (itr != num1.rend()) {
    std::cout << *itr << std::endl;
    itr++;
  }

  // const reverse over a list
  std::list<std::string> li{"Hello", "World"};
  auto it2 = li.crbegin();
  std::cout << *it2 << std::endl;
  it2++;
  std::cout << *it2 << std::endl;

  // iterator over a map
  std::map<std::string, std::string> m{{"Sharan", "C++"}, {"Dhoni", "Cricket"}};
  auto it3 = m.begin();
  while (it3 != m.end()) {
    std::cout << it3->first << " " << it3->second << std::endl;
    it3++;
  }
}

void test5() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto start = vec.begin() + 2;
  auto finish = vec.end() - 3;

  while (start != finish) {
    std::cout << *start << " ";
    start++;
  }
}

int main() {
  std::vector<int> v{
      10, 20, 30, 40,
      50, 60}; // bigin() starts from 0. end() is n + 1. So, we use end() - 1

  // display(v);
  // test1(v);
  // test2();
  // test3();
  // test4();
  test5();

  return 0;
}