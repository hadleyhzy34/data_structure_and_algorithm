#include <iostream>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
public:
  bool canPartition(std::vector<int> &nums) {
    int n = nums.size();
    /* std::sort(nums.begin(), nums.end()); */
    std::unordered_set<int> dp[n][n];
    for (auto l = 1; l <= n; l++) {
      for (auto i = 0; i + l - 1 < n; i++) {
        if (l == 1) {
          dp[i][i].insert(nums[i]);
          dp[i][i].insert(-nums[i]);
        } else {
          for (auto key : dp[i][i + l - 2]) {
            dp[i][i + l - 1].insert(key - nums[i + l - 1]);
            dp[i][i + l - 1].insert(key + nums[i + l - 1]);
          }
        }
      }
    }
    for (auto i = 0; i < n - 1; i++) {
      for (auto key : dp[0][i]) {
        if (dp[i + 1][n - 1].find(key) != dp[i + 1][n - 1].end()) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(std::vector<int> &nums, int idx, int cur) {
    if (idx == nums.size()) {
      return cur == 0;
    } else {
      bool pos = dfs(nums, idx + 1, cur + nums[idx]);
      bool neg = dfs(nums, idx + 1, cur - nums[idx]);
      return pos || neg;
    }
  }

  bool newPartition(std::vector<int> &nums) {
    int n = nums.size();
    /* std::sort(nums.begin(), nums.end()); */
    /* std::unordered_set<int> dp[n][n]; */
    std::unordered_set<int> dp;

    for (auto i = 0; i < n; i++) {
      if (i == 0) {
        dp.insert(nums[i]);
        dp.insert(-nums[i]);
      } else {
        for (auto key : dp) {
          dp.erase(key);
          dp.insert(key + nums[i]);
          dp.insert(key - nums[i]);
        }
      }
    }
    return dp.find(0) != dp.end();
  }
};
