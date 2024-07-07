#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int getMoneyAmount(int n) {
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    /* dp[1] = 0; */
    /* dp[2] = 1; */
    for (int l = 1; l <= n; l++) {
      for (int i = 1; i + l - 1 <= n; i++) {
        if (l == 1) {
          dp[i][i + l - 1] = 0;
        } else {
          int total = INT_MAX;
          for (int j = i; j <= i + l - 1; j++) {
            total = std::min(total, dp[i][j] + j + dp[j][i + l - 1]);
          }
          dp[i][i + l - 1] = total;
        }
      }
    }
    return dp[1][n];
  }
};
