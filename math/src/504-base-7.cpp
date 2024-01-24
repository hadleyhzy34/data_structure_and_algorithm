#include <iostream>
#include <string.h>

class Solution {
public:
  std::string convertToBase7(int num) {
    char sign = (num > 0) ? '\0' : '-';
    std::string res = "";
    while (num) {
      res = std::to_string(num % 7) + res;
      num = std::floor((num - num % 7) / 7);
    }
    res = sign + res;
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
