/*
Given a string s, partition s such that every
substring
 of the partition is a
palindrome
. Return all possible palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]


Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

#include <cstddef>
#include <iostream>
#include <string.h>
#include <string>
#include <unordered_set>
#include <vector>

typedef std::vector<std::vector<std::string>> arrayString;

class Solution {
public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    int n = s.length();
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    /* bool dp[n][n]; */
    for (auto l = 1; l <= n; l++) {
      for (auto i = 0; i + l - 1 < n; i++) {
        dp[i][i + l - 1] = false;
        if (l == 1) {
          dp[i][i + l - 1] = true;
        } else if (s[i] == s[i + l - 1] &&
                   (i + 1 >= i + l - 2 || dp[i + 1][i + l - 2] == true)) {
          dp[i][i + l - 1] = true;
        } else {
          dp[i][i + l - 1] = false;
        }
      }
    }
    dfs(s, {}, 0, dp);
    return palindromes;
  }

  void dfs(std::string s, std::vector<std::string> cur, int idx,
           std::vector<std::vector<bool>> dp) {
    if (idx == s.length()) {
      palindromes.push_back(cur);
      return;
    }
    for (auto j = idx; j < s.length(); j++) {
      if (dp[idx][j]) {
        cur.push_back(s.substr(idx, j - idx + 1));
        dfs(s, cur, j + 1, dp);
        cur.erase(cur.end() - 1);
      }
    }
  }

private:
  std::vector<std::vector<std::string>> palindromes;
};
