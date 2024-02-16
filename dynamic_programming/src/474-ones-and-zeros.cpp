#include <iostream>
#include <string>
#include <vector>

int findMaxForm(std::vector<std::string> &strs, int m, int n) {
  int size = strs.size();
  int dp[m][n];
  dp[0][0] = 0;
  std::vector<std::pair<int, int>> arr(size);
  for (auto i = 0; i < size; i++) {
    for (auto c : strs[i]) {
      if (c == '0') {
        arr[i].first++;
      } else {
        arr[i].second++;
      }
    }
  }
  for (auto i = 0; i < m; i++) {
    for (auto j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 0;
      } else {
      }
    }
  }
}

int findMaxSlice(std::vector<std::string> &strs, int m, int n) {
  int size = strs.size();
  std::vector<std::vector<int>> dp(m);
  int dp[m][n];
  dp[0][0] = 0;
  std::vector<std::pair<int, int>> arr(size);
  for (auto i = 0; i < size; i++) {
    for (auto c : strs[i]) {
      if (c == '0') {
        arr[i].first++;
      } else {
        arr[i].second++;
      }
    }
  }
  for (auto i = 0; i < m; i++) {
    for (auto j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 0;
      } else {
        continue;
      }
    }
  }
}
