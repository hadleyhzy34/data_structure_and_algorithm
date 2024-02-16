#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxProduct(std::vector<int> &nums) {
    int n = nums.size();
    int pos[n];
    int neg[n];
    int res = INT_MIN;
    for (auto i = 0; i < n; i++) {
      if (nums[i] == 0) {
        pos[i] = 0;
        neg[i] = 0;
      } else {
        if (i == 0) {
          //   pos[i] = std::max(0, nums[i]);
          //   neg[i] = std::min(0, nums[i]);
          pos[i] = nums[i];
          neg[i] = nums[i];
        } else {
          pos[i] = std::max(
              nums[i], std::max(pos[i - 1] * nums[i], neg[i - 1] * nums[i]));
          neg[i] = std::min(
              nums[i], std::min(neg[i - 1] * nums[i], pos[i - 1] * nums[i]));
        }
      }
      res = std::max(res, pos[i]);
    }
    return res;
  }
};
