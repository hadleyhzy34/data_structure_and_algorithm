#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
  int countDigitOne(int n) {
    int dp[1 + n];
    dp[0] = 0;
    dp[1] = 1;
    return dp[n];
  }
};
