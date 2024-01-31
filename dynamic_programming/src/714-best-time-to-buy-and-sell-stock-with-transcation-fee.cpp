#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices, int fee) {
  int n = prices.size();
  int b[n];
  int s[n];
  int c[n];
  b[0] = -prices[0];
  s[0] = 0;
  for (auto i = 1; i < prices.size(); i++) {
    b[i] = std::max(s[i - 1] - prices[i], b[i - 1]);
    s[i] = std::max(b[i - 1] + prices[i] - fee, s[i - 1]);
  }
  return s[n - 1];
}
