//
//  467_unique_substrings_in_wraparound_string.cpp
//  leet_Code_Dynamic_Programming
//
//  Created by Hadley on 21.07.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int findSubstringInWraproundString(string p) {
    vector<string> res;
    auto n = p.length();
    bool sub[n + 1][n + 1];
    memset(sub, false, sizeof(sub));

    for (int i = 1; i <= n; i++) {
      sub[i][i] = true;
      res.push_back(p.substr(i - 1, 1));
    }

    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        sub[i][j] = sub[i][j - 1] && ((p[j - 1] - p[j - 2]) == 1 ||
                                      (p[j - 1] - p[j - 2]) == -25);
        if (sub[i][j])
          res.push_back(p.substr(i - 1, j - i + 1));
      }
    }

    sort(res.begin(), res.end());
    return std::distance(res.begin(), std::unique(res.begin(), res.end()));
  }
};

class Solution2 {
public:
  int findSubstringInWraproundString(string p) {
    int ans = 0, j;
    vector<int> dp(26, 0);
    for (int i = 0; i < p.size(); i = j) {
      j = i + 1;
      while (j < p.size() &&
             (p[j] - p[j - 1] == 1 || (p[j - 1] == 'z' && p[j] == 'a')))
        ++j;
      string t = p.substr(i, j - i);
      for (int k = 0; k < t.size(); ++k) {
        if (dp[t[k] - 'a'] < t.size() - k)
          dp[t[k] - 'a'] = t.size() - k;
      }
    }
    for (int i = 0; i < 26; ++i)
      ans += dp[i];
    return ans;
  }
};
