#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int minCut(std::string s) {
    int n = s.length();
    int dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        dp[i] = 0;
      } else {
        dp[i] = i;
        if (dp[1][i - 1] == 0 && s[0] == s[i]) {
          dp[i]
        }
      }
    }
    for (int l = 1; l <= n; l++) {
      for (int i = 0; i + l - 1 < n; i++) {
        if (l == 1) {
          dp[i][i] = 0;
        } else {
          dp[i][i + l - 1] = l - 1;
          if (dp[i + 1][i + l - 2] == 0 && s[i] == s[i + l - 1]) {
            dp[i][i + l - 1] = 0;
            continue;
          } else {
            for (int j = i; j < i + l - 1; j++) {
              int cur = dp[i][j] + dp[j + 1][i + l - 1] + 1;
              dp[i][i + l - 1] = std::min(dp[i][i + l - 1], cur);
            }
          }
        }
      }
    }
    return dp[0][n - 1];
  }

private:
  std::unordered_map<int, int> umap;
};
