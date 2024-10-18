#include <functional>
#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<double> medianSlidingWindow(std::vector<int> &nums, int k) {
    std::priority_queue<std::pair<int, int>> l;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<int>>
        r;

    std::vector<double> res;
    int iLen = (k & 1) ? k / 2 + 1 : k / 2;
    for (auto i = 0; i < nums.size(); i++) {
      if (i >= k - 1) {
        if (i == k - 1) {
          while (l.size() > iLen) {
            r.push(l.top());
            l.pop();
          }
        }
        while (!l.empty() && l.top().second < i - k + 1) {
          l.pop();
        }
        while (!r.empty() && r.top().second < i - k + 1) {
          r.pop();
        }
        if (l.empty() || nums[i] <= l.top().first) {
          l.push(std::make_pair(nums[i], i));
          r.push(l.top());
          l.pop();
        } else {
          r.push(std::make_pair(nums[i], i));
          l.push(r.top());
          r.pop();
        }
        if (k & 1) {
          res.push_back((double)l.top().first);
        } else {
          res.push_back(((double)l.top().first + (double)r.top().first) / 2);
        }
      } else {
        l.push(std::make_pair(nums[i], i));
      }
    }
    return res;
  }
};
