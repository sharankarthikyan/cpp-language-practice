#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

// display the array -- not the size MUST be included
// when passing std::array to a function
void display(const std::array<int, 5> &arr) {
  std::cout << "[ ";
  for (auto const i : arr) {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}

void test1() {
  std::cout << "==========================================" << std::endl;
  std::array<int, 5> arr1{1, 2, 3, 4,
                          5}; // we need to specify the size of an array.
  std::array<int, 5> arr2;

  display(arr1);
  display(arr2); // May be some garbage values

  arr2 = {10, 20, 30, 40, 50};
  display(arr1);
  display(arr2);

  std::cout << "Size of arr1 is " << arr1.size() << std::endl;
  std::cout << "Size of arr2 is " << arr2.size() << std::endl;

  arr1[0] = 100;
  arr1.at(1) = 1000; // best approach: it does bounce checking.
  display(arr1);

  std::cout << "Front of arr2 " << arr2.front() << std::endl;
  std::cout << "Back of arr2 " << arr2.back() << std::endl;
}

void test2() {
  std::cout << "==========================================" << std::endl;
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  std::array<int, 5> arr2{10, 20, 30, 40, 50};
  display(arr1);
  display(arr2);

  arr1.fill(0);
  display(arr1);
  display(arr2);

  arr1.swap(arr2);
  display(arr1);
  display(arr2);
}

void test3() {
  std::cout << "==========================================" << std::endl;
  std::array<int, 5> arr1{1, 2, 3, 4, 5};

  int *ptr = arr1.data(); // returns the first index of an array.

  std::cout << ptr << std::endl;
  *ptr = 1000;

  display(arr1);
}

void test4() {
  std::cout << "==========================================" << std::endl;
  std::array<int, 5> arr1{2, 1, 3, 5, 4};
  display(arr1);

  std::sort(arr1.begin(), arr1.end());
  display(arr1);
}

void test5() {
  std::cout << "==========================================" << std::endl;
  std::array<int, 5> arr1{2, 1, 3, 5, 4};

  std::array<int, 5>::iterator min_num =
      std::min_element(arr1.begin(), arr1.end());
  auto max_num = std::max_element(arr1.begin(), arr1.end());
  std::cout << "Min: " << *min_num << ", Max: " << *max_num << std::endl;
}

void test6() {
  std::cout << "==========================================" << std::endl;
  std::array<int, 5> arr1{2, 1, 3, 3, 4};

  auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
  if (adjacent != arr1.end()) {
    std::cout << "Adjacent element found with value: " << *adjacent
              << std::endl;
  } else {
    std::cout << "Adjacent Not found" << std::endl;
  }
}

void test7() {
  std::cout << "==========================================" << std::endl;
  std::array<int, 5> arr1{1, 2, 3, 4, 5};

  int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
  std::cout << "Sum of the elements in arr1 is " << sum << std::endl;
}

void test8() {
  std::cout << "==========================================" << std::endl;
  std::array<int, 12> arr1{2, 1, 3, 3, 4, 3, 3, 3, 4, 3, 3, 7};

  int count = std::count(arr1.begin(), arr1.end(), 3);
  std::cout << "Found 3: " << count << " times" << std::endl;
}

void test9() {
  std::cout << "==========================================" << std::endl;
  std::array<int, 12> arr1{2, 1, 3, 50, 100, 200, 400, 500, 1000, 1200};

  int count = std::count_if(arr1.begin(), arr1.end(),
                            [](int x) { return x > 10 && x < 1000; });
  std::cout << "Found " << count << " matches" << std::endl;
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
  test9();
  return 0;
}