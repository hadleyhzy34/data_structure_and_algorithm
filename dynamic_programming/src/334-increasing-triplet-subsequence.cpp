#include <climits>
#include <iostream>
#include <vector>

bool increasingTriplet(std::vector<int> &nums) {
  int n = nums.size();
  int first = INT_MAX;
  int second = INT_MAX;

  for (auto i = 0; i < n; i++) {
    if (nums[i] > second) {
      return true;
    } else {
      if (nums[i] <= first) {
        first = nums[i];
      } else {
        second = nums[i];
      }
    }
  }
  return false;
}
