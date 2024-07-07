#include <iostream>
#include <stack>
#include <string.h>

class Solution {
public:
  std::string removeKdigits(std::string num, int k) {
    std::stack<int> st;
    for (auto i = 0; i < num.length(); i++) {
      if (i == 0) {
        st.push(int(num[i] - '0'));
      } else {
      }
    }
  }
};
