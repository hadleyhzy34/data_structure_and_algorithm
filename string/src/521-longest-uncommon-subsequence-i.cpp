#include <iostream>
#include <string.h>

class Solution {
public:
  int findLUSlength(string a, string b) {
    return (a != b) ? max(a.length(), b.length()) : -1;
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
