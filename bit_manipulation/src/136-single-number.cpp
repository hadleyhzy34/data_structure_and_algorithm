#include <iostream>
#include <vector>

class Solution {
public:
  int singleNumber(std::vector<int> &nums) {
    int res = 0;
    for (auto num : nums) {
      res = res ^ num;
    }
    return res;
  }

private:
};
