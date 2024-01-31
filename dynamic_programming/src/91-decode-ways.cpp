#include <iostream>
#include <stdlib.h>
#include <string.h>

int numDecodings(std::string s) {
  int n = s.length();
  int dp[n];
  for (auto i = 0; i < n; i++) {
    // check current char if its not zero
    if (s[i] - '0' > 0) {
      dp[i] = (i > 0) ? dp[i - 1] : 1;
    } else {
      dp[i] = 0;
    }
    if (i >= 1) {
      if (s[i - 1] != '0') {
        if (std::atoi(s.substr(i - 1, 2).c_str()) <= 26) {
          if (i >= 2) {
            dp[i] += dp[i - 2];
          } else {
            dp[i] += 1;
          }
        }
      }
    }
  }
  return dp[n - 1];
}
