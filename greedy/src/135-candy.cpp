#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
  int candy(std::vector<int> &ratings) {
    int n = ratings.size();

    std::vector<int> res(n, 1);
    for (int i = 1; i < ratings.size(); i++) {
      if (ratings[i] > ratings[i - 1]) {
        res[i] = res[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1]) {
        res[i] = std::min(res[i + 1] + 1, res[i]);
      }
    }
    return std::accumulate(res.begin(), res.end(), 0);
  }
};
