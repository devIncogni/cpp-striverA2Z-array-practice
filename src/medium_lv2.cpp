#include "medium_lv2.h"
#include <utility>

std::string twoSumV1(std::vector<int> array, int sum) {

  for (int i{}; i < array.size(); ++i) {
    for (int j{i + 1}; j < array.size(); ++j) {
      if (array[i] + array[j] == sum) {
        return "YES";
      }
    }
  }
  return "NO";
}

std::pair<int, int> twoSumV2(std::vector<int> array, int sum) {
  for (int i{}; i < array.size(); ++i) {
    for (int j{i + 1}; j < array.size(); ++j) {
      if (array[i] + array[j] == sum) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}
