#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
  int dp[m][n];
  for (auto i = 0; i < m; i++) {
    for (auto j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 1;
      } else {
        dp[i][j] = 0;
        if (j > 0) {
          dp[i][j] += dp[i][j - 1];
        }
        if (i > 0) {
          dp[i][j] += dp[i - 1][j];
        }
      }
    }
  }
  return dp[m - 1][n - 1];
}
