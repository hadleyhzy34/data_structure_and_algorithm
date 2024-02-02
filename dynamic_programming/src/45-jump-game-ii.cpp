#include <climits>
#include <iostream>
#include <vector>

int jump(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> dp(n, INT_MAX);
  dp[0] = 0;

  for (auto i = 0; i < n; i++) {
    for (auto j = i; j <= std::min(i + nums[i], n - 1); j++) {
      dp[j] = std::min(dp[i] + 1, dp[j]);
    }
  }
  return dp[n - 1];
}

int jump_v1(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> dp(n, INT_MAX);
  dp[0] = 0;

  for (auto i = 0; i < n; i++) {
    dp[j] =
        std::min() for (auto j = i; j <= std::min(i + nums[i], n - 1); j++) {
      dp[j] = std::min(dp[i] + 1, dp[j]);
    }
  }
  return dp[n - 1];
}
