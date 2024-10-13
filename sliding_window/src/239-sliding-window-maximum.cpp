#include <iostream>
#include <strings.h>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
    std::vector<int> res;
    int n = nums.size();
    std::deque<std::pair<int, int>> q;
    for (auto i = 0; i < n; i++) {
      if (i == 0) {
        q.push_back(std::make_pair(nums[i], i));
      } else {
        while (!q.empty() && q.front().second + k - 1 < i) {
          q.pop_front();
        }
        while (!q.empty()) {
          if (q.back().first >= nums[i]) {
            break;
          } else {
            q.pop_back();
          }
        }
        q.push_back(std::make_pair(nums[i], i));
      }
      res.push_back(q.front().first);
    }
    return res;
  }
};
