#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    int n = temperatures.size();
    std::vector<int> res(n, 0);
    std::stack<int> st;
    for (auto i = 0; i < temperatures.size(); i++) {
      if (i == 0) {
        st.push(i);
      } else {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
          res[st.top()] = i - st.top();
          st.pop();
        }
        st.push(i);
      }
    }
    return res;
  }
};
