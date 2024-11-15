#include <iostream>
#include <utility>

class Solution {
public:
  std::vector<int> countSmaller(std::vector<int> &nums) {
    std::vector<std::pair<int, int>> inums;
    int i = 0;
    for (auto num : nums) {
      inums.push_back(std::make_pair(num, i++));
    }
    std::vector<int> res(nums.size());
    std::sort(inums.begin(), inums.end());
    for (i = 0; i < nums.size(); i++) {
      int cnt = 0;
      for (int j = 0; j < i; j++) {
        if (inums[j].second > inums[i].second) {
          cnt++;
        }
      }
      res[inums[i].second] = cnt;
    }
    return res;
  }
};
