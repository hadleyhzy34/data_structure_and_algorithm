#include <iostream>
#include <vector>

class Solution {
public:
  int combinationSum(std::vector<int> nums, int target) {
    int n = nums.size();
    backTrack(nums, 0, 0, target);
    return res;
  }
  void backTrack(std::vector<int> nums, int idx, int cur, int target) {
    if (cur > target) {
      return;
    } else if (cur == target) {
      res++;
      return;
    } else {
      for (auto i = idx; i < nums.size(); i++) {
        backTrack(nums, i, cur + nums[i], target);
      }
    }
  }

private:
  int res = 0;
};
