#include <iostream>
#include <vector>

int nthUglyNumber(int n) {
  int dp[n];
  dp[0] = 1;
  int two = 0;
  int three = 0;
  int five = 0;
  for (auto i = 1; i < n; i++) {
    int twoC = dp[two] * 2;
    int threeC = dp[three] * 3;
    int fiveC = dp[five] * 5;
    if (twoC <= threeC && twoC <= fiveC) {
      dp[i] = twoC;
      two++;
    } else if (threeC <= twoC && threeC <= fiveC) {
      dp[i] = threeC;
      three++;
    } else if (fiveC <= twoC && fiveC <= threeC) {
      dp[i] = fiveC;
      five++;
    }
    if (dp[i] == dp[i - 1]) {
      i--;
    }
  }
  return dp[n - 1];
}
