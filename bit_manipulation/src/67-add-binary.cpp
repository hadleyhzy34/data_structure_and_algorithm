#include <iostream>
#include <strings.h>

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    std::string res = "";
    int c = 0;
    int m = a.length();
    int n = b.length();

    for (auto i = 0; i < std::max(a.length(), b.length()); i++) {
      if (m - i - 1 >= 0) {
        c += a[m - i - 1] - '0';
      }

      if (n - i - 1 >= 0) {
        c += b[n - i - 1] - '0';
      }

      if (c == 0) {
        res = '0' + res;
        c = 0;
      } else if (c == 1) {
        res = '1' + res;
        c = 0;
      } else if (c == 2) {
        res = '0' + res;
        c = 1;
      } else if (c == 3) {
        res = '1' + res;
        c = 1;
      }
    }
    if (c == 1) {
      res = '1' + res;
    }

    return res;
  }
};
