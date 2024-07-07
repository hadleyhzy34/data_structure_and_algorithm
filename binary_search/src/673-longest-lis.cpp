#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int findNumberOfLIS(std::vector<int> &nums) {
    int n = nums.size();
    // dp[i][j], number of ways to build sequence
    // with length
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n, 0));
    int len = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i == 0) {
        dp[++len].push_back(nums[i]);
      } else {
        if (nums[i] > dp[len].back()) {
          dp[++len].push_back(nums[i]);
        } else {
          // two insert operations
          int l = 1;
          int r = len;
          int pos = 1;
          while (l <= r) {
            int m = (l + r) / 2;
            if (dp[m].back() < nums[i]) {
              l = m + 1;
              pos = m;
            } else {
              r = m - 1;
            }
          }
          // insert nums[i] into dp[pos+1]
          l = 0;
          r = dp[pos + 1].size() - 1;
          int idx = l;
          while (l <= r) {
            int m = (l + r) / 2;
            if (dp[pos + 1][m] < nums[i]) {
              l = m + 1;
              idx = m;
            } else {
              r = m - 1;
            }
          }
          dp[pos + 1].insert(dp[pos + 1].begin() + idx, nums[i]);
        }
      }
    }
    return dp[len].size();
  }
};
