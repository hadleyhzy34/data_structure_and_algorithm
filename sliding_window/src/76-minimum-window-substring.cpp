#include <climits>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> ut;
    for (auto c : t) {
      ut[c]--;
    }
    int tLen = t.length();
    int tCnt = 0;
    int j = 0;
    int minLen = INT_MAX;
    std::string res = "";
    for (int i = 0; i < s.length(); i++) {
      if (ut.count(s[i])) {
        ut[s[i]]++;
        if (ut[s[i]] <= 0) {
          tCnt++;
        }
        if (tCnt < tLen) {
          continue;
        } else {
          while (j <= i) {
            if (!ut.count(s[j])) {
              j++;
            } else if (ut[s[j]] - 1 >= 0) {
              ut[s[j]]--;
              j++;
            } else {
              break;
            }
          }
          //   std::cout<<i<<" "<<j<<std::endl;
          if (i - j + 1 < minLen) {
            minLen = i - j + 1;
            res = s.substr(j, i - j + 1);
          }
        }
      } else {
        continue;
      }
    }
    return res;
  }
};
