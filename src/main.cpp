#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

int largestNumInArray(std::vector<int> array, int max, int pointer) {
  if (pointer == array.size()) {
    return max;
  }
  if (array[pointer] >= max) {
    max = array[pointer];
  }

  return largestNumInArray(array, max, pointer + 1);
}

int secondLargest(std::vector<int> array) {

  int largest{INT_MIN};
  int secondLargest{INT_MIN};

  for (auto it : array) {
    if (it > largest) {
      secondLargest = largest;
      largest = it;
    } else if (it > secondLargest && it < largest) {
      secondLargest = it;
    }
  }
  return secondLargest;
}

bool isSorted(std::vector<int> array) {
  int i{0}, j{1}, c{0};
  while (array[i++] <= array[j++] && j < array.size()) {
    c++;
  }
  return (c == array.size() - 2);
}

void removeDupes(std::vector<int> &array) {

  for (int i{0}; i + 1 < array.size(); ++i) {
    if (array[i] == array[i + 1]) {
      array.erase(array.begin() + i);
      i--;
    }
  }
}

int main() {
  std::cout << "Welcome to array practice. All Solutions to Array problems in "
               "Strivers A2Z DSA Sheet\n";

  std::vector<int> array{1, 5, 4, 7, 9, 3, 6, 4, -5};
  std::cout << largestNumInArray(array, array[0], 0);
  std::cout << '\n';
  std::cout << secondLargest(array);
  std::cout << '\n';
  std::cout << isSorted({1, 1, 2, 2, 4, 4, 5, 5});
  std::cout << '\n';

  removeDupes(array);
  for (auto it : array) {
    std::cout << it << " ";
  }
  std::cout << '\n';

  return 0;
}
