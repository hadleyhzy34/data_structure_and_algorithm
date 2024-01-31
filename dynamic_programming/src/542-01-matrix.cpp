#include <climits>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

matrix updateMatrix_v0(matrix &mat) {
  int m = mat.size();
  int n = mat[0].size();

  matrix dp(m, std::vector<int>(n, 0));
  for (auto i = 0; i < m; i++) {
    for (auto j = 0; j < n; j++) {
      dp[i][j] = (mat[i][j] == 1) ? INT_MAX : 0;
    }
  }
  for (int k = 0; k < m + n; k++) {
    for (auto i = 0; i < m; i++) {
      for (auto j = 0; j < n; j++) {
        if (dp[i][j] == 0 || dp[i][j] == 1)
          continue;
        int u = (i > 0) ? dp[i - 1][j] : INT_MAX;
        int d = (i < m - 1) ? dp[i + 1][j] : INT_MAX;
        int l = (j > 0) ? dp[i][j - 1] : INT_MAX;
        int r = (j < n - 1) ? dp[i][j + 1] : INT_MAX;
        int cur = std::min(std::min(u, d), std::min(l, r));
        if (dp[i][j] - 1 <= cur) {
          continue;
        } else {
          dp[i][j] = cur + 1;
        }
      }
    }
  }
  return dp;
}

matrix updateMatrix_v1(matrix &mat) {
  int m = mat.size();
  int n = mat[0].size();

  matrix dp(m, std::vector<int>(n, INT_MAX));

  for (auto i = 0; i < m; i++) {
    for (auto j = 0; j < n; j++) {
      if (mat[i][j] == 0) {
        dp[i][j] = 0;
        continue;
      }
    }
  }
  for (int k = 0; k < m + n; k++) {
    for (auto i = 0; i < m; i++) {
      for (auto j = 0; j < n; j++) {
        if (dp[i][j] == 0 || dp[i][j] == 1)
          continue;
        int u = (i > 0) ? dp[i - 1][j] : INT_MAX;
        int d = (i < m - 1) ? dp[i + 1][j] : INT_MAX;
        int l = (j > 0) ? dp[i][j - 1] : INT_MAX;
        int r = (j < n - 1) ? dp[i][j + 1] : INT_MAX;
        int cur = std::min(std::min(u, d), std::min(l, r));
        if (dp[i][j] - 1 <= cur) {
          continue;
        } else {
          dp[i][j] = cur + 1;
        }
      }
    }
  }
  return dp;
}
