#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int numberOfArithmeticSlices(std::vector<int> &nums) {
    int n = nums.size();
    // f[i][d] number of ways to construct sequencewith nums[i] ending at the
    // end of sequence while
    std::vector<std::unordered_map<int, int>> umap(n);
    int dp[n];

    for (int i = 0; i < n; i++) {
      dp[i] = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] - umap[i])
      }
    }
  }
};
