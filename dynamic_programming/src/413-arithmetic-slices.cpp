#include <iostream>
#include <vector>

int numberOfArithmeticSlices(std::vector<int> &nums) {
  int n = nums.size();
  int diff = 0;
  int curLength = 1;
  //   int res = 0;
  int curRes = 0;
  for (auto i = 1; i < n; i++) {
    if (curLength <= 1) {
      diff = nums[i] - nums[i - 1];
      curLength++;
    } else {
      if (nums[i] - nums[i - 1] == diff) {
        curLength++;
        if (curLength >= 3) {
          curRes += (curLength - 2);
        }
        // res = std::max(res, curRes);
      } else {
        curLength = 2;
        diff = nums[i] - nums[i - 1];
        // curRes = 0;
      }
    }
  }
  //   return res;
  return curRes;
}
