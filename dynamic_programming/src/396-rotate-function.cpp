#include <climits>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int maxRotateFunction(std::vector<int> &nums) {
    int sum = 0;
    int wSum = 0;
    int n = nums.size();

    for (auto i = 0; i < nums.size(); i++) {
      sum += nums[i];
      wSum += i * nums[i];
    }

    int cur = wSum;
    int res = wSum;

    for (auto i = 1; i < nums.size(); i++) {
      cur = cur + sum - n * nums[n - 1 - (i - 1)];
      // std::cout<<cur<<" "<<i<<" "<<std::endl;
      res = std::max(res, cur);
    }
    return res;
  }
};
