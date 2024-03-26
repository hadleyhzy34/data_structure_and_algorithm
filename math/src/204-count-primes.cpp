#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int countPrimes(int n) {
    std::vector<int> dp(1 + n, 1);
    for (auto i = 2; i <= std::sqrt(n); i++) {
      if (dp[i] == 1) {
        for (auto j = i * i; j <= n; j += i) {
          dp[j] = 0;
        }
      }
    }
    int res = 0;
    for (auto i = 2; i <= n - 1; i++) {
      if (dp[i] == 1)
        res++;
    }
    return res;
  }
};
