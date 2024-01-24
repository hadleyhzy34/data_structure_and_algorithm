#include <cctype>
#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  std::string reverseWords(std::string s) {
    int startIdx = 0;
    for (auto i = 0; i < s.length(); i++) {
      if (std::isspace(s[i])) {
        std::reverse(s.begin() + startIdx, s.begin() + i);
        startIdx = i + 1;
      }
    }
    std::reverse(s.begin() + startIdx, s.end());
    return s;
  }
  void reverseString(std::vector<char> &s) {
    int n = s.size();
    for (int i = 0; i * 2 < n; i++) {
      std::swap(s[i], s[n - 1 - i]);
    }
  }
  std::string reverseStr(std::string s, int k) {
    int sign = 1;
    int cnt = 0;
    for (auto i = 0; i < s.length(); i++) {
      cnt++;
      if (cnt == k) {
        if (sign == 1) {
          std::reverse(s.begin() + i - k + 1, s.begin() + i + 1);
        }
        sign = -sign;
      }
    }
    if (sign) {
      std::reverse(s.end() - 1 - cnt + 1, s.end());
    }
    return s;
  }
};
