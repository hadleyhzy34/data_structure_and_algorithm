#include <cstring>
#include <iostream>
#include <vector>

class Solution {
public:
  int countArrangement(int n) {
    int dp[1 + n][1 + n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
    }
    return dp[1][n];
  }
};
