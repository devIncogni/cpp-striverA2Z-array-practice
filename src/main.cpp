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

  
  std::vector<int> arr012{2,1,2,0,2,1,1,0,0};
  sort012v2(arr012);
  printArray(arr012);

  return 0;
}
