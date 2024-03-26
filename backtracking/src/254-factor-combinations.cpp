#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> getFactors(int n) {
    std::vector<int> nums = {n};
    backtrack(nums);
    return res;
  }

  void backtrack(std::vector<int> &nums) {
    if (nums.size() >= 2) {
      res.push_back(nums);
    }
    for (auto i = 0; i < nums.size(); i++) {
      int tmp = nums[i];
      for (auto j = 2; j * j < nums[i]; j++) {
        if (nums[i] % j == 0) {
          nums[i] = j;
          nums.push_back(nums[i] / j);
          backtrack(nums);
          nums[i] = tmp;
          nums.pop_back();
        }
      }
    }
  }

private:
  std::vector<std::vector<int>> res;
};
