#include <iostream>
#include <vector>

typedef std::vector<int> List;

int backtrack(List nums, int i, int cur, int target) {
  if (i == nums.size()) {
    return (cur == target) ? 1 : 0;
  }
  int positive = backtrack(nums, i + 1, cur + nums[i], target);
  int negtive = backtrack(nums, i + 1, cur - nums[i], target);

  return positive + negtive;
}

int backtrack_v0(List nums, int i, int remain) {
  if (i == nums.size()) {
    return (remain == 0) ? 1 : 0;
  }
  int positive = backtrack_v0(nums, i + 1, remain - nums[i]);
  int negtive = backtrack_v0(nums, i + 1, remain + nums[i]);

  return positive + negtive;
}

void backtrack_v1(List nums, int i, int remain, int &cnt) {
  if (i == nums.size()) {
    cnt++;
    return;
  }
  backtrack_v1(nums, i + 1, remain - nums[i], cnt);
  backtrack_v1(nums, i + 1, remain + nums[i], cnt);
}

int findTargetSumWays(List nums, int target) {
  int n = nums.size();
  int res = backtrack(nums, 0, 0, target);
  return res;
}

// dp based method
int findTargetSumWays_v0(List nums, int target) {}
