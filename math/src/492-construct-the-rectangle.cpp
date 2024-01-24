#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> constructRectangle(int area) {
    if (area == 1) {
      return {1, 1};
    }

    int l = std::ceil(std::sqrt(area));
    while (area % l != 0) {
      l++;
    }
    return {l, area / l};
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
