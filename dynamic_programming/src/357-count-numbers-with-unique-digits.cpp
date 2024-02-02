#include <iostream>
#include <math.h>
#include <vector>

int countNumbersWithUniqueDigits(int n) {
  int dp[n];
  dp[0] = 1;
  for (auto i = 1; i < n; i++) {
    dp[i] = dp[i - 1] * 9;
  }
  return std::pow(10.0, n) - dp[n - 1];
}
