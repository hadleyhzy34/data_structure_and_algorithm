#include <climits>
#include <cstring>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrice;

class Solution {
public:
  int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    int dp_rec[m][n];
    memset(dp_rec, 0, sizeof(dp_rec));
    for (auto i = m - 1; i >= 0; i--) {
      for (auto j = n - 1; j >= 0; j--) {
        if (i < m - 1 && j < n - 1) {
          dp_rec[i][j] =
              std::max(dp_rec[i + 1][j], dp_rec[i][j + 1]) + dungeon[i][j];
        } else if (i == m - 1 || j == n - 1) {
          dp_rec[i][j] = (i == m - 1) ? dp_rec[i][j + 1] + dungeon[i][j]
                                      : dp_rec[i + 1][j] + dungeon[i][j];
        } else {
          dp_rec[i][j] = dungeon[i][j];
        }
      }
    }
    int dp_cur[m][n];
    memset(dp_cur, 0, sizeof(dp_cur));
    int dp_min[m][n];
    memset(dp_min, INT_MAX, sizeof(dp_min));
    for (auto i = 0; i < m; i++) {
      for (auto j = 0; j < n; j++) {
        if (i > 0 && j > 0) {
          int l = std::min(
              dp_cur[i][j - 1] + dungeon[i][j],
              std::min(dp_min[i][j - 1], dp_rec[i][j] + dungeon[i][j]));
          int d = std::min(
              dp_cur[i - 1][j] + dungeon[i][j],
              std::min(dp_rec[i][j] + dungeon[i][j], dp_min[i - 1][j]));
          if (l > d) {
            dp_cur[i][j] = dp_cur[i][j - 1] + dungeon[i][j];
            dp_min[i][j] = l;
          } else {
            dp_cur[i][j] = dp_cur[i - 1][j] + dungeon[i][j];
            dp_min[i][j] = d;
          }
        } else if (i > 0 || j > 0) {
          dp_cur[i][j] = (i > 0) ? dp_cur[i - 1][j] + dungeon[i][j]
                                 : dp_cur[i][j - 1] + dungeon[i][j];
          dp_min[i][j] = (i > 0) ? std::min(dp_cur[i][j], dp_min[i - 1][j])
                                 : std::min(dp_cur[i][j - 1], dp_min[i][j - 1]);
        } else {
          dp_cur[i][j] = dungeon[i][j];
          dp_min[i][j] = dungeon[i][j];
        }
      }
    }
    return dp_min[m - 1][n - 1];
  }
};
