#include <algorithm>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

template <typename T> void display(std::stack<T> st) {
  std::cout << "[ ";
  while (!st.empty()) {
    T ele = st.top();
    st.pop();
    std::cout << ele << " ";
  }
  std::cout << "]" << std::endl;
}

template <typename T1, typename T2> void display(std::stack<T1, T2> st) {
  std::cout << "[ ";
  while (!st.empty()) {
    T1 ele = st.top();
    st.pop();
    std::cout << ele << " ";
  }
  std::cout << "]" << std::endl;
}

int main() {
  std::stack<int> s;
  std::stack<int, std::vector<int>> s1;
  std::stack<int, std::list<int>> s2;
  std::stack<int, std::deque<int>> s3;

  for (int i : {1, 2, 3, 4, 5}) {
    s.push(i);
  }
  display(s);

  s.push(100);
  display(s);

  s.pop();
  s.pop();
  display(s);

  while (!s.empty()) {
    s.pop();
  }
  display(s);

  std::cout << "Size: " << s.size() << std::endl;

  s.push(10);
  display(s);

  s.top() = 100;
  display(s);

  std::stack<int, std::vector<int>> second(std::vector<int>(
      3, 100)); // Normally, we can't initialize stack. We need to push into the
                // stack. With the help of vector, stack and deque we can
                // initialize the statck. ---- std::stack uses std::deque as
                // underlying container
  display(second);
  return 0;
}
