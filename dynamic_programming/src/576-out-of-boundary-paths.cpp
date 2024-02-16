#include <iostream>
#include <vector>
typedef std::vector<std::vector<long>> mat;

class Solution {

public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    long res = 0;

    int modulo = 1000000007;

    mat dp(m + 2, std::vector<long>(n + 2, 0));
    //   for (auto i = 0; i < m + 2; i++) {
    //     for (auto j = 0; j < n + 2; j++) {
    //       dp[i][j] = (startRow == i + 1 && startColumn == j + 1) ? 1 : 0;
    //     }
    //   }
    dp[startRow + 1][startColumn + 1] = 1;
    for (auto k = 0; k < maxMove; k++) {
      mat pre = dp;
      for (auto i = 0; i < m + 2; i++) {
        for (auto j = 0; j < n + 2; j++) {
          dp[i][j] = 0;
          if ((i == 0 && ((j == 0) || (j == n + 1))) ||
              (i == m + 1 && ((j == n + 1) || (j == 0)))) {
            continue;
          } else if (i == 0) {
            long u = pre[i + 1][j];
            dp[i][j] = u;
            res += (dp[i][j] % modulo);
          } else if (j == 0) {
            long r = pre[i][j + 1];
            dp[i][j] = r;
            res += (dp[i][j] % modulo);
          } else if (i == m + 1) {
            long d = pre[i - 1][j];
            dp[i][j] = d;
            res += (dp[i][j] % modulo);
          } else if (j == n + 1) {
            long l = pre[i][j - 1];
            dp[i][j] = l;
            res += (dp[i][j] % modulo);
          } else {
            long l = (j > 1) ? pre[i][j - 1] : 0;
            long r = (j < n) ? pre[i][j + 1] : 0;
            long u = (i > 1) ? pre[i - 1][j] : 0;
            long d = (i < m) ? pre[i + 1][j] : 0;
            dp[i][j] = (l + r + u + d) % modulo;
          }
          //   res += dp[i][j];
        }
      }
    }
    return res % 1000000007;
  }
};
