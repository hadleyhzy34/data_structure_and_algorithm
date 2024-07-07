#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string largestNumber(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), [](const int a, const int b) {
      return std::to_string(a) + std::to_string(b) >
             std::to_string(b) + std::to_string(a);
    });
    std::string res = "";
    for (auto num : nums) {
      // res = s + res;
      res += std::to_string(num);
    }

    if (nums[0] == 0) {
      return "0";
    }
    return res;
  }
};
