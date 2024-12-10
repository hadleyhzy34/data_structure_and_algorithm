#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> largestDivisibleSubset(std::vector<int> &nums) {
    std::vector<int> res = {};
    if (!nums.empty()) {
      res = {nums[0]};
    }
    int len = 1;
    int largestIdx = 0;
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    // std::vector<std::vector<int>> dp(n);
    int dp[n];
    memset(dp, 0, sizeof(dp));

    int prev[n];
    std::fill(prev, prev + n, -1);

    for (int i = 0; i < n; i++) {
      dp[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            prev[i] = j;
            if (dp[i] > len) {
              len = dp[i];
              largestIdx = i;
            }
          }
        }
      }
    }

    int t = prev[largestIdx];
    res = {nums[largestIdx]};
    while (t != -1) {
      res.emplace_back(nums[t]);
      t = prev[t];
    }

    return res;
  }
};
