// map doesn't allow duplicate elements. But, some other map allow duplicate
// key elements.

#include <algorithm>
#include <iostream>
#include <map>
#include <set>

void display(const std::map<std::string, std::set<int>> &m) {
  std::cout << "[ ";
  for (const auto ele : m) {
    std::cout << ele.first << ":[ ";
    for (const auto set_ele : ele.second) {
      std::cout << set_ele << " ";
    }
    std::cout << "] ";
  }
  std::cout << "]" << std::endl;
}

template <typename T1, typename T2> void display(const std::map<T1, T2> &m) {
  std::cout << "[ ";
  for (const auto ele : m) {
    std::cout << ele.first << ":" << ele.second << " ";
  }
  std::cout << "]" << std::endl;
}

void test1() {
  // Maps
  std::cout << "Test1 ====================================" << std::endl;

  std::map<std::string, int> m{
      {"Sharan", 21}, {"Dhoni", 38}, {"Raina", 35}}; // maps are ordering by key
  display(m);

  m.insert(std::pair<std::string, int>("Jadu", 30));
  display(m);

  m.insert(std::make_pair("Kohli", 30));
  display(m);

  m.insert(
      std::make_pair("Kohli", 30)); // duplicate key entries not possible in map
  display(m);

  m["Sharan"] = 10;
  display(m);

  m["Sharan"] += 30;
  display(m);

  m.erase("Kohli");
  display(m);

  std::cout << "Count for Sharan " << m.count("Sharan") << std::endl;
  std::cout << "Count for Kohli " << m.count("Kohli") << std::endl;

  auto it = m.find("Sharan");
  if (it != m.end()) {
    std::cout << "Found: " << it->first << ":" << it->second << std::endl;
  }

  m.clear();

  display(m);
}

void test2() {
  std::cout << "Test2 ====================================" << std::endl;

  std::map<std::string, std::set<int>> grades{{"Sharan", {98, 97, 95, 100}},
                                              {"Dhoni", {99, 98, 95, 99}},
                                              {"Raina", {99, 96, 94, 99}}};
  display(grades);

  grades["Raina"].insert(100);
  display(grades);

  auto it = grades.find("Raina");
  if (it != grades.end()) { // Raina found
    it->second.insert(1000);
  }
  display(grades);
}

int main() {
  // test1();
  test2();
  return 0;
}