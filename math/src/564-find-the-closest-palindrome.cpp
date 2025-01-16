#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string nearestPalindromic(std::string n) {
    std::string res = n;
    int nLen = n.length();
    for (int i = n.length() - 1; i >= nLen / 2; i--) {
      if (n[i] == n[nLen - i - 1]) {
        continue;
      } else {
        n[i] = n[nLen - i - 1];
      }
    }
    if (res != n) {
      return n;
    } else {
      res[0] -= 1;
      res[nLen] -= 1;
      if (res[0] == '0') {
        return res.substr(1);
      }
      return res;
    }
  }
};
