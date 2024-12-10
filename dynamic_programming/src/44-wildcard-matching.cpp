#include <cassert>
#include <cstring>
#include <iostream>
#include <string>

class Solution {
public:
  bool isMatch(std::string s, std::string p) {
    int m = s.length();
    int n = p.length();
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;
    int i = 1;
    while (i<=n&&p[i-1] == '*') {
      dp[0][i] = 1;
      i++;
    }

    int state[n + 1];
    memset(state, 0, sizeof(state));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s[i - 1] == p[j - 1] || p[j] == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          dp[i][j] = dp[i][j - 1];
          if (state[j] == 1) {
            dp[i][j] = 1;
          }
          state[j] |= dp[i][j];
        }
      }
    }

    return dp[m][n];
  }
};

void runTests(Solution s) {
    // Test Case 1: Basic match
    // assert(s.isMatch("aa", "a*") == true); // '*' allows multiple 'a's.

    // Test Case 2: Single character and wildcard
    assert(s.isMatch("aa", "*") == true); // '.*' matches any sequence.

    // // Test Case 3: Exact match
    // assert(s.isMatch("abc", "abc") == true); // Matches exactly.

    // // Test Case 4: Dot wildcard
    // assert(s.isMatch("abc", "a.c") == true); // '.' matches any single character.

    // // Test Case 5: Zero occurrences of character before '*'
    // assert(s.isMatch("ab", ".*c") == false); // '.*' matches "ab", but there's no 'c'.

    // // Test Case 6: Pattern longer than string
    // assert(s.isMatch("a", "ab*") == true); // 'b*' matches zero occurrences of 'b'.

    // // Test Case 7: Empty string and empty pattern
    // assert(s.isMatch("", "") == true); // Both empty.

    // // Test Case 8: Empty string with pattern
    // assert(s.isMatch("", ".*") == true); // '.*' matches zero or more of any character.

    // // Test Case 9: Mismatched pattern
    // assert(s.isMatch("mississippi", "mis*is*p*.") == false); // Complex mismatch.

    // // Test Case 10: Long match
    // assert(s.isMatch("aab", "c*a*b") == true); // 'c*' is zero, 'a*' matches "aa", 'b' matches.

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
  Solution s;
    runTests(s);
    return 0;
}


