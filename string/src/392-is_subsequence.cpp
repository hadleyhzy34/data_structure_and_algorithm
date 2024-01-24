#include <iostream>
#include <string.h>

class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    // s empty
    if (s.empty())
      return true;
    int cnt = 0;
    for (auto ct : t) {
      if (ct == s[cnt]) {
        cnt++;
        if (cnt == s.length()) {
          return true;
        }
      }
    }
    return false;
  }

private:
};
