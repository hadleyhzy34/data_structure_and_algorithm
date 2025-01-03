#include <cmath>
#include <iostream>
#include <vector>
class Solution {
public:
  int countDigitOne(int n) {
    std::unordered_map<int, int> dp;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    dp[6] = 1;
    dp[7] = 1;
    dp[8] = 1;
    dp[9] = 1;

    if (n <= 9) {
      return dp[n];
    }

    int a = 1;
    int b = 1;
    while (a * std::pow(10, b) <= n) {
      int cur = a * std::pow(10, b);
      if (a == 1) {
        dp[cur] = dp[9 * std::pow(10, b - 1)] + dp[std::pow(10, b - 1)];
        a++;
      } else if (a > 1) {
        dp[cur] = dp[(a - 1) * std::pow(10, b)];
        if (a - 1 == 1) {
          dp[cur] += std::pow(10, b) - 1;
          dp[cur] += dp[std::pow(10, b)] - 1;
        } else {
          dp[cur] += dp[std::pow(10, b)] - 1;
        }
        if (a == 9) {
          a = 1;
          b++;
        } else {
          a++;
        }
      }
      //   std::cout<<cur<<" "<<dp[cur]<<std::endl;
    }
    int res = 0;
    std::string tmp = std::to_string(n);
    int len = tmp.length();
    for (int i = 0; i < tmp.length(); i++) {
      int t = tmp[i] - '0';
      if (t == 1) {
        res += dp[t * std::pow(10, len - 1 - i)];
        if (i < tmp.length() - 1) {
          res += std::stoi(tmp.substr(i + 1));
        }
      } else {
        res += dp[t * std::pow(10, len - 1 - i)];
      }
      //   std::cout<<i<<" "<<res<<" "<<tmp[i]<<std::endl;
    }
    return res;
  }
};
