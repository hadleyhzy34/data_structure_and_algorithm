#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  bool validWordAbbreviation(std::string word, std::string abbr) {
    int aPtr = 0;
    for (auto i = 0; i < word.length(); i++) {
      if (std::isdigit(abbr[aPtr])) {
        int tmp = 0;
        if (abbr[aPtr] == '0') {
          return false;
        }
        while (std::isdigit(abbr[aPtr])) {
          tmp = tmp * 10 + (abbr[aPtr] - '0');
          aPtr++;
        }
        i += (tmp - 1);
        if (i >= word.length() || tmp > 20) {
          return false;
        }
      } else {
        if (word[i] == abbr[aPtr]) {
          aPtr++;
        } else {
          return false;
        }
      }
    }
    return aPtr == abbr.length();
  }
};
