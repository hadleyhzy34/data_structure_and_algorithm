#include <iostream>

class Solution {
public:
  int arrangeCoins(int n) {
    // declare type with long to prevent integer overflow
    long res = 0;
    for (auto i = 0; i < n; i++) {
      res += i;
      if (res > n) {
        return i - 1;
      } else if (res == n) {
        return i;
      }
    }
    return 0;
  }
  int arrangeCoinsBinarySearch(int n) {
    int l = 1;
    int r = n;
    int m = (l + r) / 2;
    while (l >= r) {
      long total = m * (m + 1) / 2;
      if (total == n) {
        return m;
      } else if (total < n) {
        l = m + 1;
      } else {
        if ((m * (m - 1) / 2) < n) {
          return m - 1;
        } else {
          r = m - 1;
        }
      }
    }
    return 0;
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
