#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  std::vector<int> sortArray(std::vector<int> &nums) {
    if (nums.empty())
      return {};
    int n = nums.size();
    sort(nums, 0, n - 1);
    return nums;
  }

  void sort(std::vector<int> &nums, int l, int r) {
    if (l == r) {
      return;
    } else {
      int m = (l + r) / 2;
      sort(nums, l, m);
      sort(nums, m + 1, r);
      merge(nums, l, m, r);
      return;
    }
  }
  void merge(std::vector<int> &nums, int l, int m, int r) {
    std::vector<int> tmp;
    int i = l;
    int j = m + 1;
    while (i <= m && j <= r) {
      if (nums[i] <= nums[j]) {
        tmp.push_back(nums[i]);
        i++;
      } else {
        tmp.push_back(nums[j]);
        j++;
      }
    }
    if (i <= m) {
      for (; i <= m; i++) {
        tmp.push_back(nums[i]);
      }
    } else {
      for (; j <= r; j++) {
        tmp.push_back(nums[j]);
      }
    }
    for (int k = l; k <= r; k++) {
      nums[k] = tmp[l + k];
    }
  }
};
