#include <algorithm>
#include <iostream>
#include <vector>

struct Square_Functor { // square functor
  void operator()(int x) { std::cout << x * x << " "; }
};

void squarefun(int x) { // square function
  std::cout << x * x << " ";
}

int main() {
  std::vector<int> vec{1, 2, 3};
  auto loc = std::find(vec.begin(), vec.end(), 3); // find alogorithm
  if (loc != vec.end()) {
    std::cout << *loc << std::endl;
  }

  Square_Functor square;
  std::vector<int> vec2{1, 2, 3, 4};
  std::for_each(vec2.begin(), vec2.end(), square);
  std::cout << std::endl;
  std::for_each(vec2.begin(), vec2.end(), squarefun);
  return 0;
}