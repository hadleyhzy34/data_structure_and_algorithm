/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1
and s2.

An interleaving of two strings s and t is a configuration where s and t are
divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3
+ s3 + ... Note: a + b is the concatenation of strings a and b.
*/

#include <iostream>
#include <string.h>
#include <vector>

/*
s1 = "aabcc"
s2 = "bddca"
s3 = "aadbbcbacac"
 */

class Solution {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    int m = s1.length();
    int n = s2.length();
    int l = s3.length();
    int mPtr = 0;
    int nPtr = 0;
    for (auto i = 0; i < l; i++) {
      if (s3[i] == s1[mPtr] && s3[i] != s2[nPtr]) {
        mPtr++;
      } else if (s3[i] == s2[nPtr] && s3[i] != s1[mPtr]) {
        nPtr++;
      } else if (s3[i] == s2[nPtr] && s3[i] == s1[mPtr]) {
        bool o1 = isInterleave(s1.substr(mPtr + 1, m - mPtr - 1),
                               s2.substr(nPtr, n - nPtr),
                               s3.substr(i + 1, l - (i + 1)));
        bool o2 = isInterleave(s1.substr(mPtr, m - mPtr),
                               s2.substr(nPtr + 1, n - nPtr - 1),
                               s3.substr(i + 1, l - (i + 1)));
        return o1 || o2;
      } else {
        return false;
      }
    }
    return (mPtr == m) && (nPtr == n);
  }
};

/*
s1 = "aabcc"
s2 = "dbbca"
s3 = "aadbbcbcac"
 */

class Task {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s1.empty()) {
      return s2 == s3;
    } else if (s2.empty()) {
      return s1 == s3;
    }
    int m = s1.length();
    int n = s2.length();
    int l = s3.length();
    int mPtr = m;
    int nPtr = n;
    int dp[m + 1][n + 1][l + 1];

    for (auto i = m; i >= 0; i--) {
      for (auto j = n; j >= 0; j--) {
        if (i == m && j == n) {
          dp[i][j][l] = 1;
          continue;
        }
        int sIdx = i + j;
        // std::cout<<i<<" "<<j<<" "<<sIdx<<std::endl;
        dp[i][j][sIdx] = 0;
        if (i != m && s1[i] == s3[sIdx] && dp[i + 1][j][sIdx + 1] == 1) {
          dp[i][j][sIdx] = 1;
        }
        if (j != n && s2[j] == s3[sIdx] && dp[i][j + 1][sIdx + 1] == 1) {
          dp[i][j][sIdx] = 1;
        }
      }
    }
    return dp[0][0][0] == 1;
  }
};

/*
follow up: using only extra O(s2.length) memory space
 */
class Task_2 {
public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s1.empty()) {
      return s2 == s3;
    } else if (s2.empty()) {
      return s1 == s3;
    }
    int m = s1.length();
    int n = s2.length();
    int l = s3.length();

    // pick dp[0][i], not picking at index i -> most left index of s1 that could
    // interleave s3
    int dp[2][n + 1];

    for (auto i = n; i >= 0; i--) {
      if (i == n) {
      }
      int s1Idx = dp[1][i + 1];
      int s3Idx = i + s1Idx;
      while (s3[s3Idx] == s1[s1Idx]) {
        s1Idx--;
      }
      dp[0][i] = s1Idx;
    }

    for (auto i = m; i >= 0; i--) {
      for (auto j = n; j >= 0; j--) {
        if (i == m && j == n) {
          dp[i][j][l] = 1;
          continue;
        }
        int sIdx = i + j;
        // std::cout<<i<<" "<<j<<" "<<sIdx<<std::endl;
        dp[i][j][sIdx] = 0;
        if (i != m && s1[i] == s3[sIdx] && dp[i + 1][j][sIdx + 1] == 1) {
          dp[i][j][sIdx] = 1;
        }
        if (j != n && s2[j] == s3[sIdx] && dp[i][j + 1][sIdx + 1] == 1) {
          dp[i][j][sIdx] = 1;
        }
      }
    }
    return dp[0][0][0] == 1;
  }
};
