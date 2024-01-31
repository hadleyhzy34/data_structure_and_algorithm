#include <climits>
#include <deque>
#include <iostream>
#include <vector>
// O(n^2) extra space
int minimumTotal_v0(std::vector<std::vector<int>> &triangle) {
  int n = triangle.size();
  int dp[n][n];

  int res = INT_MAX;
  for (auto i = 0; i < n; i++) {
    if (i == 0) {
      dp[0][0] = triangle[0][0];
      if (i == n - 1) {
        res = dp[0][0];
      }
      continue;
    }
    for (auto j = 0; j < triangle[i].size(); j++) {
      if (j == 0) {
        dp[i][j] = triangle[i][j] + dp[i - 1][j];
      } else if (j == triangle[i].size() - 1) {
        dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
      }
      if ((i == n - 1) && dp[i][j] < res) {
        res = dp[i][j];
      }
    }
  }
  return res;
}

// O(n) extra space
int minimumTotal_v1(std::vector<std::vector<int>> &triangle) {
  int n = triangle.size();
  std::deque<int> dp;

  int res = INT_MAX;
  for (auto i = 0; i < n; i++) {
    if (i == 0) {
      dp.push_back(triangle[0][0]);
      if (i == n - 1) {
        res = *dp.begin();
      }
      continue;
    }
    for (auto j = 0; j < triangle[i].size(); j++) {
      if (j == 0) {
        dp.push_front(triangle[i][j] + *dp.begin());
      } else if (j == triangle[i].size() - 1) {
        dp.push_back(triangle[i][j] + *(dp.end() - 1));
      } else {
        dp.at(j) = std::min(dp.at(j), dp.at(j + 1)) + triangle[i][j];
      }
      if ((i == n - 1) && dp[j] < res) {
        res = dp[j];
      }
    }
  }
  return res;
}
