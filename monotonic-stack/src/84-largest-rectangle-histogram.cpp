#include <cstring>
#include <iostream>

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    int n = heights.size();

    int res = 0;

    std::stack<int> l;
    std::vector<int> lh(n);

    // find each index corresponding smaller height on its left side
    for (int i = 0; i < n; i++) {
      while (!l.empty() && heights[i] <= heights[l.top()]) {
        l.pop();
      }
      if (l.empty()) {
        lh[i] = -1;
      } else {
        lh[i] = l.top();
      }
      l.push(i);
    }

    std::stack<int> r;
    std::vector<int> rh(n);

    for (int i = n - 1; i >= 0; i--) {
      while (!r.empty() && heights[i] <= heights[r.top()]) {
        r.pop();
      }
      if (r.empty()) {
        rh[i] = n;
      } else {
        rh[i] = r.top();
      }
      r.push(i);
    }

    for (int i = 0; i < n; i++) {
      res = std::max(res, heights[i] * ((rh[i] - 1) - (lh[i] + 1) + 1));
    }
    return res;
  }
};

class Solution1 {
public:
  int largestRectangleArea(std::vector<int> &heights) {
    int n = heights.size();
    // int dp[n][n];
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    // memset(dp, 0, sizeof(dp));

    std::vector<std::vector<int>> sp(n, std::vector<int>(n, 0));
    // int sp[n][n];
    // memset(sp, 0, sizeof(sp));

    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int l = 1; i + l - 1 < n; l++) {
        if (l == 1) {
          dp[i][i + l - 1] = heights[i];
          sp[i][i] = i;
          res = std::max(res, dp[i][i + l - 1]);
        } else {
          sp[i][i + l - 1] = (heights[i + l - 1] <= heights[sp[i][i + l - 2]])
                                 ? i + l - 1
                                 : sp[i][i + l - 2];
          int k = sp[i][i + l - 1];
          dp[i][i + l - 1] = std::max(l * heights[k], dp[i][i + l - 1]);
          if (k != i) {
            dp[i][i + l - 1] = std::max(dp[i][i + l - 1], dp[i][k - 1]);
          }
          if (k != i + l - 1) {
            dp[i][i + l - 1] = std::max(dp[i][i + l - 1], dp[k + 1][i + l - 1]);
          }
          res = std::max(res, dp[i][i + l - 1]);
        }
      }
    }
    return res;
  }
};
