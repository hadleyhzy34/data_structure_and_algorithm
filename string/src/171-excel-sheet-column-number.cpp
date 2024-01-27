#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  int titleToNumbner(std::string columnTitle) {
    int res = 0;
    int n = columnTitle.length();
    int cnt = 0;
    for (auto i = 0; i < n; i++) {
      res = res * 26 + int(columnTitle[i] - 'A' + 1);
    }
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
