#include <climits>
#include <iostream>
#include <vector>

int minArrayLen(int target, std::vector<int> &nums) {
  int dp[target + 1];
  for (auto i = 1; i <= target; i++) {
    dp[i] = INT_MAX;
    for (auto j = 0; j < nums.size(); j++) {
      if (nums[j] == dp[i]) {
        dp[i] = 1;
        break;
      } else {
        if (nums[j] < i) {
          dp[i] = std::min(dp[nums[j]] + dp[i - nums[j]], dp[i]);
        }
      }
    }
  }
  return dp[target];
}
