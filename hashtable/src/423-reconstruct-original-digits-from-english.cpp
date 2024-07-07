#include <iostream>
#include <strings.h>
#include <vector>

class Solution {
public:
  std::string originalDigits(std::string s) {
    /* std::string dict = std::string(26,'0'); */
    std::vector<int> dict(26, 0);
    for (auto c : s) {
      dict[int(c - 'a')]++;
    }
    std::string cur = "";
    dfs(dict, s.length(), cur);
    return res;
  }

  void dfs(std::vector<int> dict, int total, std::string cur) {
    if (total == 0) {
      res = cur;
      return;
    }
    for (int i = 0; i <= 9; i++) {
      std::vector<int> tmp = dict;
      bool check = true;
      for (auto c : nums[i]) {
        tmp[c - 'a']--;
        if (tmp[c - 'a'] < 0) {
          check = false;
          break;
        }
      }
      if (check) {
        dfs(tmp, total - nums[i].length(), cur + nums[i]);
      }
    }
  }

private:
  std::string res = "";
  std::vector<std::string> nums = {"zero", "one", "two",   "three", "four",
                                   "five", "six", "seven", "eight", "nine"};
};
