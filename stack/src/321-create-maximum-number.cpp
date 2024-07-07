#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

class Solution {
public:
  std::vector<int> maxNumber(std::vector<int> &nums1, std::vector<int> &nums2,
                             int k) {
    std::stack<int> s1;
    std::stack<int> s2;
    std::vector<int> res;
    for (int i = 0; i < nums1.size(); i++) {
      if (s1.empty() || s1.top() >= nums1[i]) {
        s1.push(nums1[i]);
      } else {
        while (s1.empty() || s1.top() < nums1[i]) {
          s1.pop();
        }
        s1.push(nums1[i]);
      }
      std::stack<int> tmp = s1;
      int ts = s1.size();
      std::vector<int> uv;
      while (!tmp.empty()) {
        uv.push_back(tmp.top());
        tmp.pop();
      }
      std::reverse(uv.begin(), uv.end());
      um1[ts].push_back(uv);
    }
    std::string r = "";
    for (int i = 0; i <= k; i++) {
      if (um1.count(i) && um2.count(k - i)) {
        std::string tmp = "";

        if (tmp > r) {
          r = tmp;
        }
      }
    }
    for (auto c : r) {
      res.push_back(c - '0');
    }
    return res;
  }

private:
  std::unordered_map<int, std::vector<std::vector<int>>> um1;
  std::unordered_map<int, std::vector<std::vector<int>>> um2;
};
