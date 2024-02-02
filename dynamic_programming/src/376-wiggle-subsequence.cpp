#include <iostream>
#include <vector>

int wiggleMaxLength(std::vector<int> &nums) {
  int n = nums.size();
  if (n <= 1)
    return n;
  int res = 1;
  int up[n];
  int down[n];
  up[0] = 1;
  down[0] = 1;
  if (nums[1] > nums[0]) {
    up[1] = 2;
    down[1] = 1;
  } else if (nums[1] < nums[0]) {
    up[1] = 1;
    down[1] = 2;
  } else {
    up[1] = 1;
    down[1] = 1;
  }
  for (auto i = 2; i < nums.size(); i++) {
    up[i] = 1;
    down[i] = 1;
    for (auto j = 1; j < i; j++) {
      if (nums[i] > nums[j]) {
        up[i] = std::max(down[j] + 1, up[i]);
      } else if (nums[i] < nums[j]) {
        down[i] = std::max(up[j] + 1, down[i]);
      }
    }
    res = std::max(res, std::max(up[i], down[i]));
  }
  return res;
}
