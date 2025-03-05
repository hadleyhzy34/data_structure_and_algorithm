#include <climits>
#include <iostream>

class Solution {
public:
  int splitArray(std::vector<int> &nums, int k) {
    int n = nums.size();

    int dp[n][1 + k];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = dp[i - 1][0] + nums[i];
    }

    for (int kk = 1; kk < k; kk++) {
      for (int i = 0; i < n; i++) {
        dp[i][kk] = INT_MAX;
        if (i < kk) {
          continue;
        } else {
          for (int j = 0; j < i; j++) {
            dp[i][kk] = std::min(dp[i][kk],
                                 std::max(dp[j][kk - 1], dp[i][0] - dp[j][0]));
          }
        }
        // std::cout<<i<<" "<<kk<<" "<<dp[i][kk]<<std::endl;
      }
    }

    return dp[n - 1][k - 1];
  }
};
int main() {
  std::vector nums = {7, 2, 5, 10, 8};
  int k = 2;
  Solution sol;
  sol.splitArray(nums, k);
}
