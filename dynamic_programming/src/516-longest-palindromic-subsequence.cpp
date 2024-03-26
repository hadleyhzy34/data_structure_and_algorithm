#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  int longestPalindromeSubseq(std::string s) {
    int maxLength = 1;
    int n = s.length();
    int dp[n][n + 1];
    memset(dp, 0, sizeof(dp));
    for (auto l = 1; l <= n; l++) {
      for (auto i = 0; i + l - 1 < n; i++) {
        if (l == 1) {
          dp[i][l] = 1;
        } else {
          dp[i][l] = std::max(dp[i][l], dp[i + 1][l - 1]);
          dp[i][l] = std::max(dp[i][l], dp[i][l - 1]);
          if (s[i] == s[i + l - 1]) {
            dp[i][l] = std::max(dp[i][l], dp[i + 1][l - 2] + 2);
          }
        }
      }
    }
    return dp[0][n];
  }
};
