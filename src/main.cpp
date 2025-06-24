#include "./easy_lv1.h"
#include "medium_lv2.h"
#include <iostream>
#include <utility>
#include <vector>

void printArray(std::vector<int> array) {
  for (auto it : array) {
    std::cout << it << " ";
  }
  std::cout << '\n';
}

int main() {
  std::cout << "Welcome to array practice. All Solutions to Array problems in "
               "Strivers A2Z DSA Sheet\n";

  std::vector<int> array{0, 3, 0, 0, 9, 3, 6, 4, 5};

  std::cout << twoSumV1TwoPointer(array, 10);

  std::pair<int, int> twoSum = twoSumV2(array, 10);
  std::cout << twoSum.first << ',' << twoSum.second;

  std::cout << '\n';

  return 0;
}
