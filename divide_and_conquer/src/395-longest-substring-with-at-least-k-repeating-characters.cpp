#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int longestSubstring(std::string s, int k) {
    if (s.length() < k) {
      return 0;
    }
    std::unordered_map<char, int> uc;
    for (int i = 0; i < s.length(); i++) {
      // std::cout<<i<<" "<<s<<" "<<s[i]<<std::endl;
      uc[s[i]]++;
    }
    int pre = 0;
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
      if (uc[s[i]] < k) {
        if (pre == i) {
          pre++;
        } else {
          res = std::max(res, longestSubstring(s.substr(pre, i - pre), k));
          pre = i + 1;
        }
      } else {
        continue;
      }
    }
    // if(pre == 0){
    //     res = s.length();
    // }
    if (pre <= s.length() - k + 1 - 1) {
      // std::cout<<"PRE: "<<pre<<" "<<s<<" "<<res<<std::endl;
      if (pre == 0) {
        res = s.length() - 1 - pre + 1;
      } else {
        res = std::max(
            res, longestSubstring(s.substr(pre, s.length() - 1 - pre + 1), k));
      }
      //   res = s.length() - 1 - pre + 1;
    }
    return res;
  }
};
