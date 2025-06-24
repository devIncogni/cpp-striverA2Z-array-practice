#include "medium_lv2.h"
#include <unordered_map>
#include <utility>

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
