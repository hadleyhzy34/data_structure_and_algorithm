#include <cctype>
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

class Solution {
public:
  std::string decodeString(std::string s) {
    std::string res = "";
    std::stack<int> s1;
    std::stack<std::string> s2;
    int idx = 0;
    while (idx < s.length()) {
      if (std::isdigit(s[idx])) {
        int tmp = s[idx] - '0';
        while (std::isdigit(s[++idx])) {
          tmp = tmp * 10 + s[idx];
        }
        s1.push(tmp);
      } else if (s[idx] == '[') {
        std::string tmp = "";
        while (std::isalpha(s[++idx])) {
          tmp += s[idx];
        }
        s2.push(tmp);
      } else if (s[idx] == ']') {
        for (auto i = 0; i < s1.top(); i++) {
          res += s2.top();
        }
        s1.pop();
        s2.pop();
      }
    }
    return res;
  }
};
