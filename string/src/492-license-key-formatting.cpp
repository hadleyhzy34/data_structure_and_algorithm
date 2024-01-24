#include <algorithm>
#include <cctype>
#include <iostream>
#include <string.h>

class Solution {
public:
  std::string licenseKeyFormatting(std::string s, int k) {
    std::string res = "";
    int n = s.length();
    int cnt = 0;
    // remove dash and toupper char
    for (auto i = n - 1; i >= 0; i--) {
      if (s[i] == '-') {
        s.erase(i, 1);
        i++;
        continue;
      }
      res.push_back(std::toupper(s[i]));
      cnt++;
      if (cnt % k == 0) {
        res.push_back('-');
        cnt = 0;
      }
    }

    // remove last dash
    if (res.size() > 0 && res.back() == '-') {
      res.pop_back();
    }

    // reverse string
    std::reverse(res.begin(), res.end());

    return res;
  }
  Solution();
  Solution(Solution &&) = default;
  Solution(const Solution &) = default;
  Solution &operator=(Solution &&) = default;
  Solution &operator=(const Solution &) = default;
  ~Solution();

private:
};

Solution::Solution() {}

Solution::~Solution() {}
