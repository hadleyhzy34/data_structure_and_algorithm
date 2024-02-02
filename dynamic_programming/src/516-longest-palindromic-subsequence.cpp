#include <iostream>
#include <string.h>
#include <vector>

int longestPalindromeSubseq(std::string s) {
  int maxLength = 1;
  std::string maxString = "";
  int n = s.length();
  int dp[n][n];
  for (auto l = 1; l - 1 < n; l++) {
    for (auto i = 0; i + l - 1 < n; i++) {
      if (l == 1) {
        dp[i][i + 1] = 1;
      } else {
        dp[i][i + l - 1] = dp[i + 1][i + l - 2] && (s[i] == s[i + l - 1]);
        if (dp[i][i + l - 1] > maxLength) {
          maxLength = dp[i][i + l - 1];
          maxString = s.substr(i, l);
        }
      }
    }
  }
  return maxLength;
}
