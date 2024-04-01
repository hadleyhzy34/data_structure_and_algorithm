#include <iostream>
#include <string.h>

class Solution {
public:
  std::string removeKdigits(std::string num, int k) {

    std::stack<std::pair<int, int>> snode;
    int j = 0;
    for (auto i = 0; i < num.length(); i++) {
      if (i + 1 - snode.size() == k) {
        j = i;
        break;
      }
      int cur = num[i] - '0';
      while (!snode.empty() && cur < snode.top().second &&
             i - snode.size() < k) {
        snode.pop();
      }
      snode.push(std::make_pair(i, cur));
      // if(i+1-snode.size()==k){
      //     j = i;
      //     break;
      // }
    }
    string res = "";
    while (!snode.empty()) {
      res = std::string(1, '0' + snode.top().second) + res;
      snode.pop();
    }
    res = res + num.substr(j + 1, num.length() - j - 1);
    // remove trailing zeros
    while (res[0] == '0' && res.length() > 1) {
      res = res.substr(1, res.length() - 1);
    }
    return (res.empty()) ? "0" : res;
  }
};
