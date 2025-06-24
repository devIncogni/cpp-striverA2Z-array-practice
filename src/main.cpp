#include "./easy_lv1.h"
#include <iostream>
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

  std::vector<int> array{0, 5, 0, 0, 9, 3, 6, 4, -5};

  std::cout << longestSubArrayWithSumTwoPointer({-1, 1, 1}, 1);
  std::cout << '\n';

  return 0;
}
