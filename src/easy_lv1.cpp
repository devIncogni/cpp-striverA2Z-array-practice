#include "./easy_lv1.h"

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

int maxConsecutiveOnes(std::vector<int> binaryArray) {

  int counter{0};
  int max{0};

  for (auto it : binaryArray) {
    if (it == 1) {
      counter++;
    } else {
      max = std::max(counter, max);
      counter = 0;
    }
  }
  return max;
}

int elementAppearsOnce(std::vector<int> array) {
  std::unordered_map<int, int> freq;

  for (auto it : array) {
    freq[it]++;
  }

  for (auto it : freq) {
    if (it.second == 1) {
      return it.first;
    }
  }
  return 0;
}

int elementAppearsOnceXOR(std::vector<int> array) {

  int XOR{};
  for (auto it : array) {
    XOR ^= it;
  }
  return XOR;
}

int longestSubArrayWithSum(std::vector<int> array, int sum) {

  std::vector<int> subArray;
  int sumSubArr{};
  int maxSize{};

  for (int i{}; i < array.size(); ++i) {
    sumSubArr = 0;
    subArray.clear();

    for (int j{i}; j < array.size(); ++j) {
      // sumSubArr = 0;
      subArray.push_back(array[j]);
      sumSubArr += array[j];

      if (sumSubArr == sum) {
        maxSize = std::max(static_cast<int>(subArray.size()), maxSize);
        break;
      }
      if (sumSubArr > sum) {
        break;
      }
    }
  }
  return maxSize;
}

int longestSubArrayWithSumHash(std::vector<int> array, int sum) {
  std::unordered_map<int, int> prefixSum;
  int sumArr{0};
  int remainderSum{};
  int maxLen{0};

  for (int i{}; i < array.size(); ++i) {
    sumArr += array[i];

    if (prefixSum.find(sumArr) == prefixSum.end()) {
      prefixSum[sumArr] = i;
    }

    remainderSum = sumArr - sum;

    if (sumArr == sum) {
      maxLen = std::max(maxLen, i + 1);
    }

    if (prefixSum.find(remainderSum) != prefixSum.end()) {
      maxLen = std::max(maxLen, i - prefixSum[remainderSum]);
    }
  }
  return maxLen;
}

int longestSubArrayWithSumTwoPointer(std::vector<int> array, int sum) {

  int left{0}, right{0}, sumArr{array[0]};
  int maxLen{0};

  while (right < array.size()) {

    while (left <= right && sumArr > sum) {
      sumArr -= array[left++];
    }

    if (sumArr == sum) {
      maxLen = std::max(maxLen, right - left + 1);
    }

    right++;
    if (right < array.size()) {
      sumArr += array[right];
    }
  }

  return maxLen;
}
