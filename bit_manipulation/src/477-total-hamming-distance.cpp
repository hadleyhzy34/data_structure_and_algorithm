#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int totalHammingDistance(std::vector<int> &nums) {
    std::unordered_map<int, int> bmap;
    int count = 0;
    for (auto num : nums) {
      count = 0;
      while (num) {
        if (num & 1) {
          bmap[count]++;
        }
        count++;
        num >>= 1;
      }
    }
    int n = nums.size();
    int res = 0;
    for (auto [key, val] : bmap) {
      res += val * (n - val);
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
