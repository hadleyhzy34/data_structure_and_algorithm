#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
  int countRangeSum(std::vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    std::vector<std::pair<int, int>> pfx(n);
    pfx[0] = std::make_pair(nums[0], 0);
    for (int i = 1; i < n; i++) {
      pfx[i].first = pfx[i - 1].first + nums[i];
      pfx[i].second = i;
    }
    std::sort(pfx.begin(), pfx.end(),
              [](std::pair<int, int> &a, std::pair<int, int> &b) {
                return a.first < b.first;
              });
    int j = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (pfx[i].first - pfx[j].first >= upper - lower) {
        if (pfx[i].second > pfx[j].second) {
          res++;
        }
      } else {
        while (pfx[i].first - pfx[j].first < upper - lower) {
          j++;
        }
      }
    }
    return res;
  }
};
