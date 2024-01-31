#include <iostream>
#include <vector>

int rob_v0(std::vector<int> &nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0];
  int wL_oL[n];
  int wL_wL[n];
  int oL_oL[n];
  int oL_wL[n];
  for (auto i = 0; i < nums.size(); i++) {
    if (i == 0) {
      wL_oL[i] = 0;
      wL_wL[i] = nums[i];
      oL_oL[i] = 0;
      oL_wL[i] = 0;
    } else if (i == n - 1) {
      wL_oL[i] = nums[i] + oL_oL[i - 1];
      wL_wL[i] = 0;
      oL_oL[i] = std::max(oL_oL[i - 1], wL_oL[i - 1]);
      oL_wL[i] = std::max(oL_wL[i - 1], wL_wL[i - 1]);
    } else {
      wL_oL[i] = nums[i] + oL_oL[i - 1];
      wL_wL[i] = nums[i] + oL_wL[i - 1];
      oL_oL[i] = std::max(oL_oL[i - 1], wL_oL[i - 1]);
      oL_wL[i] = std::max(oL_wL[i - 1], wL_wL[i - 1]);
    }
  }
  return std::max(wL_oL[n - 1], std::max(oL_oL[n - 1], oL_wL[n - 1]));
}

int rob_v1(std::vector<int> &nums) {
  int n = nums.size();
  if (n == 1)
    return nums[0];

  int dp[n];
  for (auto i = 0; i < n - 1; i++) {
    if (i == 0) {
      dp[i] = nums[i];
    } else {
      if (i >= 2) {
        dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
      } else if (i == 1) {
        dp[i] = std::max(nums[i], dp[i - 1]);
      }
    }
  }

  int res1 = dp[n - 2];

  for (auto i = 0; i < n; i++) {
    if (i == 0) {
      dp[i] = 0;
    } else {
      if (i >= 2) {
        dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
      } else if (i == 1) {
        dp[i] = std::max(nums[i], dp[i - 1]);
      }
    }
  }

  int res2 = dp[n - 1];

  return std::max(res1, res2);
}
