#include <cstring>
#include <iostream>
#include <vector>

class Solution {
public:
  int countArrangement(int n) {
    int dp[1 + n][1 + n];
    memset(dp, 0, sizeof(dp));
    for (int l = 1; l <= n; l++) {
      for (int i = 1; i + l - 1 <= n; i++) {
        for (int j = i; j <= i + l - 1; j++) {
          if (i % j == 0) {
            dp[i][i + l - 1] += dp[i][j - 1] * dp[j + 1][i + l - 1] * 2;
          }
        }
      }
    }
    return dp[1][n];
  }
};
