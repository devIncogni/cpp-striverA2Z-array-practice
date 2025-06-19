#include <climits>
#include <cstdio>
#include <iostream>
#include <utility>
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

void printArray(std::vector<int> array) {
  for (auto it : array) {
    std::cout << it << " ";
  }
  std::cout << '\n';
}

void leftRotateByOne(std::vector<int> &array) {

  int firstElement{array[0]};
  for (int i{0}; i + 1 < array.size(); ++i) {
    array[i] = array[i + 1];
  }
  array[array.size() - 1] = firstElement;

  // Second Logic
  // array.push_back(array[0]);
  // array.erase(array.begin());
}

void reverseArray(std::vector<int> &array, int start, int end) {

  int j{end};
  for (int i{start}; i <= j; ++i) {

    std::swap(array[i], array[j--]);
  }
}

void leftRotateByN(std::vector<int> &array, int N) {

  reverseArray(array, 0, N - 1);
  reverseArray(array, N, array.size() - 1);
  reverseArray(array, 0, array.size() - 1);
}

void moveZerosToEnd(std::vector<int> &array) {

  int j{0};
  for (int i{0}; i < array.size(); ++i) {
    if (array[i] != 0) {
      continue;
    } else {
      j = i + 1 >= array.size() ? i : i + 1;
      while (array[j] == 0 && j < array.size()) {
        ++j;
        if (j == array.size()) {
          return;
        }
      }
      std::swap(array[i], array[j]);
    }
  }
}

int main() {
  std::cout << "Welcome to array practice. All Solutions to Array problems in "
               "Strivers A2Z DSA Sheet\n";

  std::vector<int> array{0, 5, 0, 0, 9, 3, 6, 4, -5};
  std::cout << largestNumInArray(array, array[0], 0);
  std::cout << '\n';
  std::cout << secondLargest(array);
  std::cout << '\n';
  std::cout << isSorted({1, 1, 2, 2, 4, 4, 5, 5});
  std::cout << '\n';

  // removeDupes(array);
  // printArray(array);

  // leftRotateByOne(array);
  // printArray(array);

  // leftRotateByN(array, 5);
  // printArray(array);
  printArray(array);
  moveZerosToEnd(array);
  printArray(array);

  return 0;
}
