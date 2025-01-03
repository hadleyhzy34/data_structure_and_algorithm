#include "iostream"
#include <string.h>
#include <vector>

class Solution {
public:
  int findIntegers(int n) {
    // dp[i]: total available numbers from 0 to 2^i-1
    std::vector<int> dp;
    dp.push_back(1);
    dp.push_back(2);
    int i;
    for (i = 2; std::pow(2, i) <= n; i++) {
      dp.push_back(dp.back() + dp[i - 2]);
    }
    i--;
    int res = 0;
    int pre = 0;
    while (n > 0 && i >= 0) {
      if(n & (1 << i)) {
        if(res>0)res--;
        res += dp[i];
        res += (pre==0)?1:0;
        pre = 1;
      } else {
        pre = 0;
      }
      dp.pop_back();
      i--;
    }
    return res;
  }
};


int main() {
  Solution solution;
  int n = 13;
  int result = solution.findIntegers(n);
  std::cout << "The number of non-negative integers less than or equal to " << n << " without consecutive ones is: " << result << std::endl;
  return 0;
}