#include <iostream>
#include <vector>

int rob(std::vector<int> &nums) {
  int n = nums.size();
  int wL[n];
  int oL[n];
  for (auto i = 0; i < nums.size(); i++) {
    if (i == 0) {
      wL[i] = nums[i];
      oL[i] = 0;
    } else {
      wL[i] = nums[i] + oL[i - 1];
      oL[i] = std::max(oL[i - 1], wL[i - 1]);
    }
  }
  return std::max(wL[n - 1], oL[n - 1]);
}
