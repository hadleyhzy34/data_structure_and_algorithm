#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices) {
  int n = prices.size();
  int b[n];
  int s[n];

  b[0] = -prices[0];
  s[0] = 0;

  int res = 0;

  for (auto i = 1; i < prices.size(); i++) {
    b[i] = std::max(s[i - 1] - prices[i], b[i - 1]);
    s[i] = std::max(s[i - 1], b[i - 1] + prices[i]);
    int bt[n - i - 1];
    int st[n - i - 1];
    bt[0] = -prices[i + 1];
    st[0] = 0;
    for (auto j = 1; j + i < n; j++) {
      bt[j] = std::max(st[j - 1] - prices[j + i], bt[j - 1]);
      st[j] = std::max(st[j - 1], b[j - 1] + prices[j + i]);
    }
    if (s[i] + st[n - i - 2] > res) {
      res = s[i] + st[n - i - 2];
    }
  }

  return std::max(res, s[n - 1]);
}
