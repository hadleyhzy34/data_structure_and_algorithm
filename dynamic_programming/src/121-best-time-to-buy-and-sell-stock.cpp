#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int n = prices.size();
    int s[n];
    int b[n];
    s[0] = 0;
    b[0] = prices[0];
    for (auto i = 1; i < prices.size(); i++) {
      s[i] = std::max(s[i - 1], prices[i] - b[i - 1]);
      b[i] = std::min(b[i - 1], prices[i]);
    }
    return s[n - 1];
  }
};
