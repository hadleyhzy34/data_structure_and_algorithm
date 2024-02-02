#include <iostream>
#include <vector>

int integerBreak(int n) {
  int dp[n + 1];
  dp[1] = 1;
  for (auto i = 2; i <= n; i++) {
    dp[i] = 1 * dp[i - 1];
    for (auto j = 2; j <= i / 2; j++) {
      dp[i] = std::max(dp[i], dp[j] * dp[i - j]);
    }
    if (i != n) {
      dp[i] = std::max(dp[i], i);
    }
    // dp[i] = std::max(dp[i],i);
  }
  return dp[n];
}
