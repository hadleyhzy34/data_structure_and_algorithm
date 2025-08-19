#include <iostream>

class Solution1 {
public:
  int findMin(std::vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      // case 2,4,5
      if (nums[l] == nums[m] && nums[m] == nums[r]) {
        l++;
        r--;
      } else if (nums[l] <= nums[m] && nums[m] <= nums[r]) {
        return nums[l];
      } else if (nums[l] <= nums[m] && nums[m] > nums[r]) { // case 3,6
        l = m + 1;
      } else if (nums[l] > nums[m] && nums[m] <= nums[r]) { // case 8,9
        l++;
        r = m;
      }
    }
    return nums[l];
  }
};
class Solution {
public:
  int findMin(std::vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] == nums[l] && nums[m] == nums[r]) {
        l++;
        r--;
      } else if (nums[m] >= nums[l] && nums[m] > nums[r]) {
        if (nums[m + 1] < nums[m]) {
          return nums[m + 1];
        } else {
          l = m + 1;
        }
      } else if (nums[m] >= nums[l] && nums[m] <= nums[r]) {
        return nums[l];
      } else if (nums[m] < nums[l] && nums[m] <= nums[r]) {
        l++;
        r = m;
      }
    }
    return nums[l];
  }
};
int main(int argc, char *argv[]) {
  // std::vector<int> v = {2, 2, 2, 0, 1};
  // std::vector<int> v = {3, 1, 1};
  std::vector<int> v = {2, 0, 1, 1, 1};

  Solution sol;
  sol.findMin(v);
  return 0;
}
