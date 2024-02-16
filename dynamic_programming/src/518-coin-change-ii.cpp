#include <climits>
#include <iostream>
#include <vector>

// wrong example
int coinChange_v0(int amount, std::vector<int> &coins) {
  if (amount == 0)
    return 0;
  int n = coins.size();
  int res = 0;
  int dp[amount + 1];
  for (auto i = 1; i <= amount; i++) {
    dp[i] = 0;
    for (auto j = 1; j <= n / 2; j++) {
      int num = dp[j] * dp[i - j];
      dp[i] += (dp[j] == -1 || dp[i - j] == 1) ? 0 : num;
    }
    for (auto k = 0; k < n; k++) {
      if (coins[k] == i) {
        dp[i]++;
      }
    }
  }
  return dp[amount];
}

int coinChange_v1(int amount, std::vector<int> &coins) {
  if (amount == 0)
    return 0;
  int n = coins.size();
  int res = 0;
  int dp[amount + 1];
  for (auto i = 1; i <= amount; i++) {
    dp[i] = 0;
    for (auto j = 0; j < n; j++) {
      dp[i] += (i > coins[j]) ? dp[i - coins[j]] : 0;
    }
  }
  return dp[amount];
}

class Solution {
public:
  int change(int amount, std::vector<int> &coins) {
    int dp[amount + 1];
    dp[0] = 0;
    for (auto i = 1; i <= amount; i++) {
      dp[i] = 0;
      for (auto j = 0; j < coins.size(); j++) {
        if (i == coins[j]) {
          dp[i]++;
        } else if (i - coins[j] > 0) {
          dp[i] += dp[i - coins[j]];
        }
      }
    }
    return dp[amount];
  }
};
