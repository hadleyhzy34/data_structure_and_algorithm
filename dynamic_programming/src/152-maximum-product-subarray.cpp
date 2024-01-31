#include <iostream>
#include <vector>

int maxProduct(std::vector<int> &nums) {
  int n = nums.size();
  int pos[n];
  int neg[n];
  for (auto i = 0; i < n; i++) {
    if (i == 0) {
      pos[0] = (nums[i] > 0) ? nums[i] : 1;
      neg[0] = (nums[i] < 0) ? nums[i] : -1;
    } else {
      if (nums[i] > 0) {
        pos[i] = std::max(nums[i] * pos[i - 1], nums[i]);
        neg[i] = std::min(nums[i] * pos[i - 1], nums[i]);
      } else if (nums[i] < 0) {
        pos[i] = std::max(pos[i - 1], nums[i] * neg[i - 1]);
        neg[i] = std::max(neg[i - 1], nums[i] * pos[i - 1]);
      }
    }
  }
  return pos[n - 1];
}
