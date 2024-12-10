#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxCoins(std::vector<int> &nums) {
    int n = nums.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int l = 1; l <= n; l++) {
      for (int i = 0; i + l - 1 < n; i++) {
        for (int j = i; j <= i + l - 1; j++) {
          if (l == 1) {
            dp[i][i] = nums[i];
          } else {
            int l = (j > i) ? nums[j - 1] : 1;
            int lV = (j > i) ? dp[i][j - 1] : 0;
            int r = (j <= i + l - 2) ? nums[j + 1] : 1;
            int rV = (j <= i + l - 2) ? dp[j + 1][i + l - 1] : 0;
            int val = l * r * nums[j];
            dp[i][i + l - 1] = std::max(
                dp[i][i + l - 1], dp[i][j - 1] + dp[j + 1][i + l - 1] + val);
          }
        }
      }
    }
    return dp[0][n - 1];
  }

private:
  int res;
  std::unordered_map<std::string, int> umap;
};
int main() {
  Solution sol;
  vector<int> nums = {3, 1, 5, 8};
  int result = sol.maxCoins(nums);
  cout << "Test 1 (Expected: 167) => " << result << endl;
  // assert(result == 167);
  return 0;
}
