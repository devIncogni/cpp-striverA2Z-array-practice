#include "medium_lv2.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

std::string twoSumV1(std::vector<int> array, int sum) {

  std::unordered_map<int, int> valueKey;
  for (int i{}; i < array.size(); ++i) {

    if (valueKey.find(array[i]) == valueKey.end()) {
      valueKey[array[i]] = i;
    }
    int rem = sum - array[i];

    if (valueKey.find(rem) != valueKey.end()) {
      return "YES";
    }
  }
  return "NO";
}

std::pair<int, int> twoSumV2(std::vector<int> array, int sum) {
  std::unordered_map<int, int> valueKey;
  for (int i{}; i < array.size(); ++i) {

    if (valueKey.find(array[i]) == valueKey.end()) {
      valueKey[array[i]] = i;
    }
    int rem = sum - array[i];

    if (valueKey.find(rem) != valueKey.end()) {
      return {valueKey[rem], i};
    }
  }
  return {-1, -1};
}

void printArray1(std::vector<int> array) {
  for (auto it : array) {
    std::cout << it << " ";
  }
  std::cout << '\n';
}

std::string twoSumV1TwoPointer(std::vector<int> array, int sum) {

  std::sort(array.begin(), array.end());
  int left{0}, right{static_cast<int>(array.size() - 1)};

  while (left < right) {
    int sumArr{array[left] + array[right]};

    if (sumArr == sum) {
      return "YES";
    }

    else if (sumArr < sum) {
      left++;
    }

    else {
      right--;
    }
  }
  return "NO";
}

std::pair<int, int> twoSumV2TwoPointer(std::vector<int> &array, int sum) {
  std::sort(array.begin(), array.end());
  int left{0}, right{static_cast<int>(array.size() - 1)};

  while (left < right) {
    int sumArr{array[left] + array[right]};

    if (sumArr == sum) {
      return {left, right};
    }

    else if (sumArr < sum) {
      left++;
    }

    else {
      right--;
    }
  }
  return {-1, -1};
}

void sort012(std::vector<int> &array) {

  int z{0}, o{0}, t{0};

  for (auto it : array) {
    if (it == 0) {
      z++;
    }

    else if (it == 1) {
      o++;
    }

    else {
      t++;
    }
  }

  int i{0};

  while (z > 0) {
    array[i++] = 0;
    --z;
  }
  while (o > 0) {
    array[i++] = 1;
    --o;
  }
  while (t > 0) {
    array[i++] = 2;
    --t;
  }
}

void sort012v2(std::vector<int> &array) {

  int start{0}, end{static_cast<int>(array.size() - 1)}, mid{0};
  while (mid < end) {
    if (array[mid] == 0) {
      std::swap(array[start], array[mid]);
      ++start;
      ++mid;
    }

    else if (array[mid] == 2) {
      std::swap(array[end], array[mid]);
      --end;
    }

    else {
      ++mid;
    }
  }
}

int majorityElement(std::vector<int> array) {

  std::unordered_map<int, int> freq;

  for (int element : array) {
    freq[element]++;
  }

  std::pair<int, int> highest{0, 0};

  for (auto it : freq) {
    if (it.second > array.size() / 2) {
      return it.first;
    }
  }

  return -1;
}

int majorityElementMoore(std::vector<int> array) {

  int count{0}, element{};
  for (int i{0}; i < array.size(); ++i) {
    if (count == 0) {
      element = array[i];
      count = 1;
    }

    else if (array[i] == element) {
      count++;
    }

    else {
      count--;
    }
  }
  return element;
}
