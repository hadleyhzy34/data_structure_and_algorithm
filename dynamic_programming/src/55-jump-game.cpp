#include <iostream>
#include <vector>

bool canJump(std::vector<int> &nums) {
  int maxR = 0;
  int n = nums.size();
  for (auto i = 0; i <= maxR; i++) {
    maxR = std::max(maxR, i + nums[i]);
    if (maxR >= (n - 1)) {
      return true;
    }
  }
  return false;
}
