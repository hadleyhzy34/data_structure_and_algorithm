#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    int rCnt = 0;
    int wCnt = 0;
    int bCnt = 0;
    for (auto i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        rCnt++;
        nums[rCnt - 1] = 0;
        if (wCnt) {
          nums[rCnt + wCnt - 1] = 1;
        }
        if (bCnt) {
          nums[rCnt + wCnt + bCnt - 1] = 2;
        }
      } else if (nums[i] == 1) {
        wCnt++;
        nums[rCnt + wCnt - 1] = 1;
        if (bCnt) {
          nums[rCnt + wCnt + bCnt - 1] = 2;
        }
      } else {
        bCnt++;
      }
    }
  }
};
