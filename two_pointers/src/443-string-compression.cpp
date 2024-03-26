#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  int compress(std::vector<char> &chars) {
    char cur = '\0';
    int cnt = 0;
    int res = 0;
    for (auto i = 0; i < chars.size(); i++) {
      if (chars[i] == cur) {
        cnt++;
      } else {
        chars[res] = chars[i];
        res++;
        while (cnt) {
          chars[res] = '0' + (cnt % 10);
          res++;
          cnt /= 10;
        }
      }
    }
    return res;
  }
};
