#include <iostream>
#include <vector>

int findNumberOfLIS(std::vector<int> &nums) {
  int n = nums.size();
  int maxLength = 1;
  int res = 1;

  int dp[n];
  for (auto i = 0; i < n; i++) {
    dp[i] = 1;
    for (auto j = 0; j < i; j++) {
      if (nums[i] > nums[j]) {
        dp[i] = std::max(dp[j] + 1, dp[i]);
      }
      if (dp[i] > maxLength) {
        maxLength = dp[i];
        res = 1;
      } else if (dp[i] == maxLength && maxLength != 1) {
        res++;
      }
    }
  }
  return res;
}
