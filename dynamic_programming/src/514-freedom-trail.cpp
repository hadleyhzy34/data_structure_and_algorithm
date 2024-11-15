#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  int findRotateSteps(std::string ring, std::string key) {
    int n1 = ring.length();
    int n2 = key.length();
    int dp[n1][n2];
    memset(dp, 0, sizeof(dp));
    // for each rotated string, how many different steps they need to reach each
    // character in key
    std::vector<std::unordered_map<char, std::vector<int>>> vu;

    // key in unordered_set form
    std::unordered_set<char> kc;
    for (auto k : key) {
      kc.insert(k);
    }
    // build vu
    for (int i = 0; i < n1; i++) {
      std::string cur = ring;
      std::rotate(cur.begin(), cur.begin() + i, cur.end());
      std::unordered_map<char, std::vector<int>> t;
      for (int j = 0; j < n1; j++) {
        if (kc.find(cur[j]) != kc.end()) {
          t[cur[j]].push_back(j);
        }
      }
      vu.push_back(t);
    }

    // dp method
    for (int i = n2 - 1; i >= 0; i--) {
      for (int j = 0; j < n1; j++) {
        std::unordered_map<char, std::vector<int>> t = vu[j];
        dp[j][i] = INT_MAX;
        for (auto tt : t[key[i]]) {
          if (i == n2 - 1) {
            dp[j][i] = std::min(dp[j][i], std::min(tt, n1 - tt));
          } else {
            dp[j][i] = std::min(dp[j][i], std::min(tt + dp[(j + tt) % n1][i]))
          }
        }
        if (i == 0) {
          res = std::min(res, dp[j][i]);
        }
      }
    }
    return res;
  }

private:
  int res = 0;
};
