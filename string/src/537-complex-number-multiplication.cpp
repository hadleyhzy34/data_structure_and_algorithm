#include <cctype>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

class Solution {
public:
  std::string complexNumberMultiply(std::string num1, std::string num2) {
    std::pair<int, int> n1 = stnum(num1);
    std::pair<int, int> n2 = stnum(num2);

    int r = n1.first * n2.first - n1.second * n2.second;
    int i = n1.first * n2.second + n2.first * n1.second;
    std::string tmp = std::to_string(r) + "+" + std::to_string(i) + "i";
    return tmp;
  }

  std::pair<int, int> stnum(std::string num) {
    std::pair<int, int> res;
    int i = 0;
    while (i < num.length()) {
      if (i == 0) {
        bool pos = true;
        if (num[i] == '-') {
          pos = false;
          i++;
        }
        int j = i;
        while (std::isdigit(num[i])) {
          i++;
        }
        res.first = atoi(num.substr(j, i - j + 1).c_str());
        res.first = (pos == true) ? res.first : -res.first;
      } else if (num[i] == '+') {
        i++;
        bool pos = true;
        if (num[i] == '-') {
          pos = false;
          i++;
        }
        int j = i;
        while (i < num.length() && std::isdigit(num[i])) {
          i++;
        }
        res.second = atoi(num.substr(j, i - j + 1).c_str());
        res.second = (pos == true) ? res.second : -res.second;
        break;
      }
    }
    return res;
  }
};
