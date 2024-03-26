#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  std::string largestNumber(std::vector<int> &nums) {

    std::vector<int> vecl;
    std::vector<std::string> vecs;
    for (auto num : nums) {
      vecs.push_back(std::to_string(num));
      vecl.push_back()
    }
    std::sort(vecs.rbegin(), vecs.rend());
    std::string res = "";
    for (auto vec : vecs) {
      res += vec;
      // res.push_back(vec);
    }
    return res;
  }
};
