#include <iostream>
#include <string.h>

class Solution {
public:
  bool checkRecord(std::string s) {
    int aCnt = 0;
    for (auto i = 0; i < s.length(); i++) {
      if (s[i] == 'A') {
        aCnt++;
        if (aCnt > 1) {
          return false;
        }
      } else if (s[i] == 'L') {
        if (i + 2 < s.length() && s.substr(i, 3) == "LLL") {
          return false;
        }
      }
    }
    return true;
  }
};
