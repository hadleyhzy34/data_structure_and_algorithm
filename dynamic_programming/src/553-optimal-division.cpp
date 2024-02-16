#include <iostream>
#include <string.h>
#include <string>
#include <vector>
typedef std::pair<float, std::string> optDiv;

class Solution {
public:
  std::string optimalDivision(std::vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return std::to_string(nums[0]);
    if (n == 2)
      return std::to_string(nums[0]) + "/" + std::to_string(nums[1]);
    optDiv num[n];
    optDiv den[n];

    num[1] = std::make_pair(nums[0], std::to_string(nums[0]));
    den[1] = std::make_pair(nums[1], std::to_string(nums[1]));

    for (auto i = 2; i < n; i++) {
      // std::cout<<den[i-1].first<<" "<<num[i-1].first<<"
      // "<<nums[i]<<std::endl;
      float opt0 = num[i - 1].first / (den[i - 1].first / float(nums[i]));
      float opt1 = float(num[i - 1].first) / den[i - 1].first / nums[i];
      if (opt0 > opt1) {
        num[i].first = num[i - 1].first;
        num[i].second = num[i - 1].second;
        den[i].first = den[i - 1].first / nums[i];
        // den[i].second = "(" + den[i - 1].second + "/" +
        // std::to_string(nums[i]) + ")";
        den[i].second = den[i - 1].second + "/" + std::to_string(nums[i]);
      } else {
        num[i].first = num[i - 1].first / den[i - 1].first;
        num[i].second = "(" + num[i - 1].second + "/" + den[i - 1].second + ")";
        den[i].first = nums[i];
        den[i].second = std::to_string(nums[i]);
      }
    }
    return num[n - 1].second + "/" + "(" + den[n - 1].second + ")";
    // return num[n - 1].second + "/" + den[n - 1].second;
  }
};
