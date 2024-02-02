#include <climits>
#include <iostream>
#include <vector>

int nthSuperUglyNumber(int n, std::vector<int> &primes) {
  int size = primes.size();
  int dp[n];
  dp[0] = 1;
  std::vector<int> idx(0, size);
  for (auto i = 1; i < n; i++) {
    int minIdx = -1;
    int curMin = INT_MAX;
    for (auto j = 0; j < size; j++) {
      long tmp = dp[idx[j]] * primes[j];
      if (tmp < curMin) {
        curMin = tmp;
        minIdx = j;
      }
    }
    if (dp[i - 1] == curMin) {
      i--;
    } else {
      dp[i] = curMin;
    }
    idx[minIdx]++;
  }
  return dp[n - 1];
}
