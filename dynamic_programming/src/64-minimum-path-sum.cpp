#include <climits>
#include <iostream>
#include <string.h>
#include <vector>

int mimPathSum(std::vector<std::vector<int>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  int dp[m][n];

  for (auto i = 0; i < m; i++) {
    for (auto j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = grid[i][j];
      } else {
        int l = (i > 0) ? dp[i - 1][j] : INT_MAX;
        int u = (j > 0) ? dp[i][j - 1] : INT_MAX;
        dp[i][j] = grid[i][j] + std::min(l, u);
      }
    }
  }
  return dp[m - 1][n - 1];
}
