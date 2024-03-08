#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  std::string findLongestWord(std::string s,
                              std::vector<std::string> &dictionary) {
    std::vector<std::string> res;
    int maxlength = 0;
    for (auto i = 0; i < dictionary.size(); i++) {
      int dptr = 0;
      for (auto j = 0; j < s.length(); j++) {
        if (dictionary[i][dptr] == s[j]) {
          dptr++;
        }
      }
      if (dptr == dictionary[i].length() && dptr > maxlength) {
        maxlength = dptr;
        res.push_back(dictionary[i]);
      }
    }
    std::sort(res.begin(), res.end());
    return res[0];
  }
};
