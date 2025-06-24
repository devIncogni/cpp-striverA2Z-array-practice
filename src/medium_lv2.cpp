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
