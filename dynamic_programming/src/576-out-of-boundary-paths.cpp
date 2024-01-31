#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> mat;

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
  int res = 0;

  mat dp(m, std::vector<int>(n, 0));
  for (auto i = 0; i < m + 2; i++) {
    for (auto j = 0; j < n + 2; j++) {
      dp[i][j] = (startRow == i + 1 && startColumn == j + 1) ? 1 : 0;
    }
  }
  for (auto k = 0; k < maxMove; k++) {
    mat pre = dp;
    for (auto i = 0; i < m + 2; i++) {
      for (auto j = 0; j < n + 2; j++) {
        int l = (j > 0) ? pre[i][j - 1] : 0;
        int r = (j < n + 1) ? pre[i][j + 1] : 0;
        int u = (i > 0) ? pre[i - 1][j] : 0;
        int d = (i < m + 1) ? pre[i + 1][j] : 0;
        if (i == 0 || j == 0 || i == m + 1 || j == n + 1) {
          res += pre[i][j];
        } else {
          dp[i][j] = l + r + u + d;
        }
      }
    }
  }
  return res;
}
