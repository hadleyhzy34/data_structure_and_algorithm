#include <iostream>
#include <math.h>
#include <unordered_map>
#include <vector>

// int countNumbersWithUniqueDigits(int n) {
//   int dp[n];
//   dp[0] = 1;
//   for (auto i = 1; i < n; i++) {
//     dp[i] = dp[i - 1] * 9;
//   }
//   return std::pow(10.0, n) - dp[n - 1];
// }

class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    int num = 1 << 10;
    // return backTrack(n, num, true);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      dp[i] = 1;
      int j = 1;
      int cur = 10;
      while (j <= i) {
        dp[i] *= (j == 1) ? cur - 1 : cur;
        cur--;
        j++;
      }
    }
    int res = 0;
    for (int i = 0; i <= n; i++) {
      res += dp[i];
    }
    return res;
  }

  // int backTrack(int n, int num, bool suffix) {
  //   if (umap.find(n) != umap.end()) {
  //     return umap[n];
  //   }

  //   if (n == 0) {
  //     return 1;
  //   }

  //   int res = 0;
  //   for (int i = 0; i <= 9; i++) {
  //     if (suffix&&i==0&&n>1) {
  //       continue;
  //     } else {
  //       if ((num & (1 << i)) == 0) {
  //         num |= (1 << i);
  //         res += backTrack(n - 1, num, false);
  //         num &= (~(1<<i));
  //       }
  //     }
  //   }
  //   umap[n] = res;
  //   return res;
  // }

private:
  std::unordered_map<int, int> umap;
};

int main() {
  Solution sol;
  // test case for normal case
  int n0 = 1;
  int res0 = sol.countNumbersWithUniqueDigits(n0);

  int n1 = 2;
  int res1 = sol.countNumbersWithUniqueDigits(n1);

  int n2 = 3;
  int res2 = sol.countNumbersWithUniqueDigits(n2);

  return 0;
}
