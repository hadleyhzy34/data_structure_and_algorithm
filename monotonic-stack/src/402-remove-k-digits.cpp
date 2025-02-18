#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  std::string removeKdigits(std::string num, int k) {
    if (num.length() <= k)
      return "0";
    int n = num.size();
    std::string st;
    // std::stack<char> st;
    int cnt = 0;
    st.push_back(num[0]);
    // st.push(num[0]);
    int i = 1;
    for (; i < n; i++) {
      //   if (cnt >= k||st.size()>(n-k)) {
      // if(cnt >= k || st.size() > (n-k)){
      if (cnt >= k) {
        break;
      } else {
        if (num[i] >= st.back()) {
          // st.push(num[i]);
          st.push_back(num[i]);
        } else {
          while (!st.empty() && cnt < k && num[i] < st.back()) {
            cnt++;
            st.pop_back();
          }
          st.push_back(num[i]);
        }
      }
    }

    // std::string res = num.substr(i,n-1-i+1-(k-cnt));
    // std::string res = num.substr(i);

    // while (!st.empty()) {
    //   res = st.top() + res;
    //   st.pop();
    // }

    std::string res = st + num.substr(i);
    res = res.substr(0, n - k);

    // remove leading zero
    while (!res.empty() && res[0] == '0') {
      res = res.substr(1);
    }
    return res.empty() ? "0" : res;
  }
};

int main() {
  std::string num = "112";
  int k = 1;
  Solution sol;
  sol.removeKdigits(num, k);
  return 0;
}
