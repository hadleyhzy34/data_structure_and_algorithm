#include <climits>
#include <iostream>
#include <vector>

int coinChange(std::vector<int> &coins, int mount) {
  if (mount == 0)
    return 0;
  int res = 0;
  int dp[mount + 1];
  for (auto i = 1; i <= mount; i++) {
    dp[i] = INT_MAX;
    for (auto j = 0; j < coins.size(); j++) {
      if (coins[j] == i) {
        dp[i] = 1;
      } else {
        int num = (coins[j] < i) ? 1 + dp[i - coins[j]] : -1;
        dp[i] = (num > 0) ? std::min(dp[i], num) : dp[i];
      }
    }
    dp[i] = (dp[i] == INT_MAX) ? -1 : dp[i];
  }
  return dp[mount];
}
