#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] < target) {
        l = m + 1;
      } else if (nums[m] > target) {
        r = m - 1;
      } else {
        int ll = m;
        int rr = m;
        while ((ll > 0 && nums[ll - 1] == target) ||
               (rr < n - 1 && nums[rr + 1] == target)) {
          if (ll > 0 && nums[ll - 1] == target) {
            ll--;
          }
          if (rr < n - 1 && nums[rr + 1] == target) {
            rr++;
          }
        }
        return {ll, rr};
      }
    }
    return {-1, -1};
  }
};

class Solution2 {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] < target) {
        l = m + 1;
      } else if (nums[m] > target) {
        r = m - 1;
      } else {
        int ll = l;
        int lr = m;
        while (ll <= lr) {
          int lm = ll + (lr - ll) / 2;
          if (nums[lm] == target) {
            lr = lm - 1;
          } else {
            ll = lm + 1;
          }
        }
        int rl = m;
        int rr = r;
        while (rl <= rr) {
          int rm = rl + (rr - rl) / 2;
          if (nums[rm] == target) {
            rl = rm + 1;
          } else {
            rr = rm - 1;
          }
        }
        return {ll, rr};
      }
    }
    return {-1, -1};
  }
};
