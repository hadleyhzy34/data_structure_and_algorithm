#include <climits>
#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  int minDistance(std::string word1, std::string word2) {
    int m = word1.length();
    int n = word2.length();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (auto i = 0; i <= m; i++) {
      for (auto j = 0; j <= n; j++) {
        dp[i][j] = i + j;
      }
    }
    for (auto i = 1; i <= m; i++) {
      for (auto j = 1; j <= n; j++) {
        dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
        dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
        for (auto k = 1; k <= j; k++) {
          if (word1[i - 1] == word2[k - 1]) {
            dp[i][j] = std::min(dp[i - 1][k - 1] + j - k, dp[i][j]);
          }
        }
      }
    }
    return dp[m][n];
  }
};

class Solution1 {
public:
  int minDistance(std::string word1, std::string word2) {
    int m = word1.length();
    int n = word2.length();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (auto i = 0; i <= m; i++) {
      for (auto j = 0; j <= n; j++) {
        dp[i][j] = i + j;
      }
    }
    for (auto i = 1; i <= m; i++) {
      for (auto j = 1; j <= n; j++) {
        dp[i][j] = std::min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};
