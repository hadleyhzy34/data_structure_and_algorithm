#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices) {
  int n = prices.size();
  int b[n];
  int s[n];
  int c[n];
  b[0] = -prices[0];
  s[0] = 0;
  c[0] = 0;
  for (auto i = 1; i < prices.size(); i++) {
    b[i] = std::max(s[i - 1] - prices[i], b[i - 1]);
    c[i] = b[i - 1] + prices[i];
    s[i] = std::max(c[i - 1], s[i - 1]);
  }
  return std::max(c[n - 1], s[n - 1]);
}
