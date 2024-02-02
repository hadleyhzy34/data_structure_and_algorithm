#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int findSubstringInWrapString(std::string s) {
  int n = s.length();
  std::unordered_set<std::string> uset;

  int dp[n];
  dp[0] = 1;
  uset.insert(s[0]);

  for (auto i = 1; i < n; i++) {
    dp[i] = 1;
    if (s[i] - s[i - 1] == 1 || (s[i] == 'a' && s[i - 1] == 'z')) {
      dp[i] = dp[i - 1] + 1;
    }
    if (s.find(s[i]) != s.end()) {
    }
  }
}
