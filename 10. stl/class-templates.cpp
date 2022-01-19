#include <iostream>
#include <string>
#include <vector>

template <typename T> // template
class Item {
private:
  std::string name;
  T value;

public:
  Item(std::string name, T value) : name{name}, value{value} {}
  std::string getName() { return name; }
  T getValue() { return value; }
};

template <typename T1, typename T2> // template
struct MyPair {
  T1 first;
  T2 second;
};

int main() {
  Item<int> item1{"pencil", 100};
  std::cout << item1.getName() << " " << item1.getValue() << std::endl;

  Item<std::string> item2{"pen", "Pencil"};
  std::cout << item2.getName() << " " << item2.getValue() << std::endl;

  Item<Item<std::string>> item3{"Rock", {"and", "Roll"}};
  std::cout << item3.getName() << " " << item3.getValue().getName() << " "
            << item3.getValue().getValue() << std::endl;

  std::cout << "=======================================" << std::endl;
  std::vector<Item<double>> vec{};
  vec.push_back(Item<double>{"A", 10.9});
  vec.push_back(Item<double>("B", 10.9));
  vec.push_back(Item<double>("C", 10.9));

  for (auto d : vec) {
    std::cout << d.getName() << " " << d.getValue() << std::endl;
  }

  std::cout << "=======================================" << std::endl;
  MyPair<std::string, int> p1{"Sharan", 100};
  MyPair<double, int> p2{10.11, 100};

  std::cout << p1.first << " " << p1.second << std::endl;
  std::cout << p2.first << " " << p2.second << std::endl;

  return 0;
}