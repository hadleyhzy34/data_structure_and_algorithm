#include <iostream>
#include <unordered_map>
#include <vector>

int integerReplacement(int n) {
  // int dp[n];
  int *dp = (int *)malloc(sizeof(int) * n);
  dp[0] = 0;
  for (auto i = 1; i < n; i++) {
    int cur = i + 1;
    // std::cout<<i<<" "<<cur<<std::endl;
    if (cur % 2 == 0) {
      dp[i] = dp[cur / 2 - 1] + 1;
    } else {
      dp[i] = std::min(dp[(cur + 1) / 2 - 1], dp[(cur - 1) / 2 - 1]) + 2;
    }
    // std::cout<<i<<" "<<cur<<" "<<dp[i]<<std::endl;
  }
  return dp[n - 1];
}

// recursion
class Solution {
public:
  int integerReplacement(int n) {
    if (n == 1)
      return 0;
    if (n % 2 == 0) {
      return integerReplacement(n / 2) + 1;
    } else {
      return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
    }
  }

private:
  std::unordered_map<int, int> umap;
};

// hash table
class Solution_v0 {
public:
  int integerReplacement(int n) {
    if (umap.find(n) != umap.end()) {
      return umap[n];
    }

    if (n == 1)
      return 0;

    if (n % 2 == 0) {
      return umap[n] = integerReplacement(n / 2) + 1;
    } else {
      return umap[n] = 2 + std::min(integerReplacement(n / 2),
                                    integerReplacement(n / 2 + 1));
    }
  }

private:
  std::unordered_map<int, int> umap;
};
