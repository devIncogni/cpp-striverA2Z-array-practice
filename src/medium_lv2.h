#ifndef MEDIUM_LV2
#define MEDIUM_LV2

#include <string>
#include <utility>
#include <vector>

std::string twoSumV1(std::vector<int> array, int sum);
std::pair<int, int> twoSumV2(std::vector<int> array, int sum);

std::string twoSumV1TwoPointer(std::vector<int> array, int sum);
std::pair<int, int> twoSumV2TwoPointer(std::vector<int> &array, int sum);

void sort012(std::vector<int> &array);
void sort012v2(std::vector<int> &array);


#endif
