#include <iostream>
#include <vector>

class Solution {
public:
  int findPeakElement(std::vector<int> &nums) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if ((m == 0 && nums[m] > nums[m + 1]) ||
          (m == n - 1 && nums[m] > nums[m - 1]) ||
          (nums[m] > std::max(nums[m - 1], nums[m + 1]))) {
        return m;
      } else if (nums[m] < nums[m + 1]) {
        l = m + 1;
      } else if (nums[m] > nums[m + 1]) {
        r = m - 1;
      }
    }
    return -1;
  }
};
