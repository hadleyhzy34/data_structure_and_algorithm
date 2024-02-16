#include <iostream>
#include <string.h>
#include <utility>
#include <vector>

class Solution {
public:
  bool predictTheWinner(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
  }

  std::pair<int, int> dfs(std::vector<int> &nums, int i, int j,
                          std::vector<std::vector<int>> dp) {
    if (i == j) {
      return std::make_pair(nums[i], 0);
    } else {
      int l1 = nums[i] + dfs(nums, i + 1, j, dp).second;
      int r1 = dfs(nums, i, j - 1, dp).second + nums[j - 1];

      int l2 = dfs(nums, i + 1, j, dp).first;
      int r2 = dfs(nums, i, j - 1, dp).first;

      return std::make_pair(std::max(l1, r1), std::max(l2, r2));
    }
  }

private:
};
