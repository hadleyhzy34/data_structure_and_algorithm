#include <climits>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
  int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    int dm[m][n];
    memset(dm, 0, sizeof(dm));
    int dc[m][n];
    memset(dc, 0, sizeof(dc));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dc[i][j] = -dungeon[i][j];
          continue;
        }
        int left = INT_MAX;
        int lm = INT_MAX;
        if (j > 0) {
          left = dc[i][j - 1] - dungeon[i][j];
          lm = dm[i][j - 1];
        }
        int up = INT_MAX;
        if (i > 0) {
          up = dc[i - 1][j] - dungeon[i][j];
          um =
        }
        dc[i][j] = std::min(left, up);
      }
    }
  };
