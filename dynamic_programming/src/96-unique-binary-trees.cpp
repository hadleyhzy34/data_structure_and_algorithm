#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  int numTrees(int n) {
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (auto i = 2; i <= n; i++) {
      dp[i] = 0;
      for (auto j = 1; j <= i; j++) {
        dp[i] += std::max(1, dp[j - 1]) * std::max(1, dp[i - j]);
        // std::cout<<i<<" "<<j<<" "<<dp[i]<<std::endl;
      }
      // std::cout<<i<<" "<<dp[i]<<std::endl;
    }
    return dp[n];
  }
};
