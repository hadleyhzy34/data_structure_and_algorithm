#include <iostream>
#include <vector>

int findLongestChain(std::vector<std::vector<int>> &pairs) {
  int n = pairs.size();
  int maxLength = 1;
  int dp[n];

  for (auto i = 0; i < n; i++) {
    dp[i] = 1;
    for (auto j = 0; j < i; j++) {
      if (pairs[i][0] > pairs[j][1]) {
        dp[i] = std::max(dp[j], dp[i]);
      }
    }
    maxLength = std::max(maxLength, dp[i]);
  }
  return maxLength;
}
