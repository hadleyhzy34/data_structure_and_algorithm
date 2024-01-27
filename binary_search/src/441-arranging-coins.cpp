#include <iostream>
#include <vector>

class Solution {
public:
  int arrangeCoins(int n) {
    int l = 0;
    int r = n;
    while (l <= r) {
      long long m = (l + r) / 2;
      if ((m + 1) * m / 2 == n) {
        return m;
      } else if ((m + 1) * m / 2 > n) {
        if ((m - 1) * m / 2 < n) {
          return m - 1;
        } else {
          r = m - 1;
        }
      } else {
        l = m + 1;
      }
    }
    return -1;
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
