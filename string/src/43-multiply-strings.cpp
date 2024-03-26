#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string>

class Solution {
public:
  std::string multiply(std::string num1, std::string num2) {
    std::string res = "";
    int cnt = 0;
    for (auto i = num2.length() - 1; i >= 0; i--) {
      std::string tmp = multiplySingle(num1, num2[i]);
      tmp += std::string(cnt, '0');
      res = add(res, tmp);
      cnt++;
    }
    return res;
  }

  std::string multiplySingle(std::string num1, char num2) {
    std::reverse(num1.begin(), num1.end());
    std::string res = "";
    int cnt = 0;
    int mul = num2 - '0';
    for (auto i = 0; i < num1.length(); i++) {
      int tmp = (num1[i] - '0') * mul + cnt;
      res += std::to_string(tmp % 10);
      cnt = tmp / 10;
    }
    if (cnt > 0) {
      res += std::to_string(cnt);
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
  std::string add(std::string num1, std::string num2) {
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    int n = std::max(num1.length(), num2.length());
    std::string res = "";
    int cnt = 0;
    for (auto i = 0; i < n; i++) {
      int tmp = cnt;
      if (i < num1.length()) {
        tmp += num1[i] - '0';
      }
      if (i < num2.length()) {
        tmp += num2[i] - '0';
      }
      res += std::to_string(tmp);
      cnt = tmp / 10;
    }
    if (cnt > 0) {
      res += std::to_string(cnt);
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
