#include <iostream>
#include <queue>

class Solution {
public:
  int smallestDistancePair(std::vector<int> &nums, int k) {
    std::priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        int cur = std::abs(nums[i] - nums[j]);
        pq.push(cur);
        while (pq.size() > k) {
          pq.pop();
        }
      }
    }
    int res = -1;
    while (!pq.empty()) {
      res = pq.top();
      pq.pop();
    }
    return res;
  }
};
