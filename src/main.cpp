#include <climits>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
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

std::vector<int> findUnion(std::vector<int> array1, std::vector<int> array2) {

  std::vector<int> unionArray;

  int i{0}, j{0};

  while (i < array1.size() && j < array2.size()) {
    if (array1[i] <= array2[j]) {
      if (unionArray.empty() || unionArray.back() != array1[i]) {
        unionArray.push_back(array1[i]);
      }
      ++i;
    } else {
      if (unionArray.empty() || unionArray.back() != array2[j]) {
        unionArray.push_back(array2[j]);
      }
      ++j;
    }
  }
  while (i < array1.size()) {
    if (unionArray.empty() || unionArray.back() != array1[i]) {
      unionArray.push_back(array1[i]);
    }
    ++i;
  }
  while (j < array2.size()) {
    if (unionArray.empty() || unionArray.back() != array2[j]) {
      unionArray.push_back(array2[j]);
    }
    ++j;
  }
  return unionArray;
}

std::vector<int> findUnionUsingMap(std::vector<int> array1,
                                   std::vector<int> array2) {

  std::vector<int> unionArray;

  std::map<int, int> mapElements;
  for (auto it : array1) {
    mapElements[it]++;
  }

  for (auto it : array2) {
    mapElements[it]++;
  }

  for (auto it : mapElements) {

    unionArray.push_back(it.first);
  }
  return unionArray;
}

std::vector<int> findUnionUsingSet(std::vector<int> array1,
                                   std::vector<int> array2) {

  std::vector<int> unionArray;
  std::set<int> setOfUnion;
  for (auto it : array1) {
    setOfUnion.insert(it);
  }
  for (auto it : array2) {
    setOfUnion.insert(it);
  }

  for (auto it : setOfUnion) {
    unionArray.push_back(it);
  }
  return unionArray;
}

int findMissing(std::vector<int> array) {

  for (int i{}; i < array.size(); ++i) {
    if (i + 1 != array[i]) {
      return i + 1;
    }
  }
  return 0;
}

int findMissingSum(std::vector<int> array) {
  int N{static_cast<int>(array.size() + 1)};
  int s1{N * (N + 1) / 2};

  int s2{};
  for (auto it : array) {
    s2 += it;
  }

  return s1 - s2;
}

int findMissingXOR(std::vector<int> array) {

  int XOR1{}, XOR2{};
  for (int i{}; i < array.size(); ++i) {
    XOR1 ^= array[i];
    XOR2 ^= i + 1;
  }

  XOR2 ^= array.size() + 1;

  return XOR1 ^ XOR2;
}

int main() {
  std::cout << "Welcome to array practice. All Solutions to Array problems in "
               "Strivers A2Z DSA Sheet\n";

  std::vector<int> array{0, 5, 0, 0, 9, 3, 6, 4, -5};

  // std::cout << largestNumInArray(array, array[0], 0);
  // std::cout << '\n';
  // std::cout << secondLargest(array);
  // std::cout << '\n';
  // std::cout << isSorted({1, 1, 2, 2, 4, 4, 5, 5});
  // std::cout << '\n';

  // removeDupes(array);
  // printArray(array);

  // leftRotateByOne(array);
  // printArray(array);

  // leftRotateByN(array, 5);
  // printArray(array);
  // printArray(array);
  // moveZerosToEnd(array);
  // printArray(array);

  std::cout << findMissingXOR({1, 2, 3, 5, 6, 7, 8});
  std::cout << '\n';

  return 0;
}
