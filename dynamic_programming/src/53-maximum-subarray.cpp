#include <iostream>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int n = nums.size();
    int sum[n];
    int lmin[n];
    int rmax[n];

    sum[0] = nums[0];
    lmin[0] = std::min(0, nums[0]);
    rmax[0] = nums[0];

    for (auto i = 1; i < nums.size(); i++) {
      sum[i] = sum[i - 1] + nums[i];
      rmax[i] = std::max(rmax[i - 1], sum[i] - lmin[i - 1]);
      lmin[i] = std::min(lmin[i - 1], sum[i]);
    }
    return rmax[n - 1];
  }
};
