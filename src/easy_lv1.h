#ifndef EASY_LV1
#define EASY_LV1

#include <climits>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

int largestNumInArray(std::vector<int> array, int max, int pointer);

int secondLargest(std::vector<int> array);

bool isSorted(std::vector<int> array);

void removeDupes(std::vector<int> &array);

void leftRotateByOne(std::vector<int> &array);

void reverseArray(std::vector<int> &array, int start, int end);

void leftRotateByN(std::vector<int> &array, int N);

void moveZerosToEnd(std::vector<int> &array);

std::vector<int> findUnion(std::vector<int> array1, std::vector<int> array2);

std::vector<int> findUnionUsingMap(std::vector<int> array1,
                                   std::vector<int> array2);

std::vector<int> findUnionUsingSet(std::vector<int> array1,
                                   std::vector<int> array2);

int findMissing(std::vector<int> array);

int findMissingSum(std::vector<int> array);

int findMissingXOR(std::vector<int> array);

int maxConsecutiveOnes(std::vector<int> binaryArray);

int elementAppearsOnce(std::vector<int> array);

int elementAppearsOnceXOR(std::vector<int> array);

int longestSubArrayWithSum(std::vector<int> array, int sum);

int longestSubArrayWithSumHash(std::vector<int> array, int sum);

int longestSubArrayWithSumTwoPointer(std::vector<int> array, int sum);

#endif
