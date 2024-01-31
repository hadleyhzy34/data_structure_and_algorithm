#include <climits>
#include <iostream>
#include <utility>
#include <vector>

int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {
  int m = dungeon.size();
  int n = dungeon[0].size();

  // first to keep current max sum value
  // second to keep lowest sum value ever in this path
  std::vector<std::vector<std::pair<int, int>>> dp(
      m, std::vector<std::pair<int, int>>(n, std::make_pair(0, 0)));

  for (auto i = 0; i < m; i++) {
    for (auto j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        dp[i][j].first = dungeon[i][j];
        dp[i][j].second = dungeon[i][j];
      } else {
        int cur_u = (i > 0) ? std::min(dp[i - 1][j].first + dungeon[i][j],
                                       dp[i - 1][j].second)
                            : INT_MIN;

        int cur_l = (j > 0) ? std::min(dp[i][j - 1].first + dungeon[i][j],
                                       dp[i][j - 1].second)
                            : INT_MIN;

        if (cur_l > cur_u) {
          dp[i][j].first = dp[i][j - 1].first + dungeon[i][j];
          dp[i][j].second = cur_l;
        } else {
          dp[i][j].first = dp[i - 1][j].first + dungeon[i][j];
          dp[i][j].second = cur_u;
        }
      }
      std::cout << i << " " << j << " " << dp[i][j].first << " "
                << dp[i][j].second << std::endl;
    }
  }
  return dp[m - 1][n - 1].second;
}
