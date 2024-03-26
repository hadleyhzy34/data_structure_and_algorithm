#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    for (auto i = 0; i < nums.size(); i++) {
      for (auto j = i + 3; j < n; j++) {
        int l = i + 1;
        int r = j - 1;
        int sum = nums[i] + nums[j];
        while (l < r) {
          if (sum + nums[l] + nums[r] == target) {
            res.push_back({nums[i], nums[l], nums[r], nums[j]});
            l++;
            r--;
          } else if (sum + nums[l] + nums[r] < target) {
            l++;
          } else {
            r--;
          }
        }
      }
    }
    return res;
  }
};
