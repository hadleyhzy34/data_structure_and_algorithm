#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <vector>

class Solution {
public:
  int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
    std::sort(envelopes.begin(), envelopes.end());
    int n = envelopes.size();

    int dp_w[n];
    memset(dp_w, 0, sizeof(dp_w));

    for (auto i = 0; i < n; i++) {
      if (i == 0) {
        dp_w[i] = 1;
      } else {
        if (envelopes[i][0] > envelopes[i - 1][0] &&
            envelopes[i][1] > envelopes[i - 1][1]) {
          dp_w[i] = dp_w[i - 1] + 1;
        } else {
          int j = i - 1;
          while (j >= 0 && (envelopes[i][0] < envelopes[j][0] ||
                            envelopes[i][1] < envelopes[j][1])) {
            j--;
          }
          if (envelopes[i][0] > envelopes[j][0] &&
              envelopes[i][1] > envelopes[j][1]) {
            dp_w[i] = dp_w[j] + 1;
          } else {
            dp_w[i] = 1;
          }
        }
      }
    }

    int dp_h[n];
    memset(dp_h, 0, sizeof(dp_h));
    std::sort(
        envelopes.begin(), envelopes.end(),
        [](std::vector<int> a, std::vector<int> b) { return a[1] < b[1]; });

    for (auto i = 0; i < n; i++) {
      if (i == 0) {
        dp_h[i] = 1;
      } else {
        if (envelopes[i][0] > envelopes[i - 1][0] &&
            envelopes[i][1] > envelopes[i - 1][1]) {
          dp_h[i] = dp_h[i - 1] + 1;
        } else {
          int j = i - 1;
          while (j >= 0 && (envelopes[i][0] < envelopes[j][0] ||
                            envelopes[i][1] < envelopes[j][1])) {
            j--;
          }
          if (envelopes[i][0] > envelopes[j][0] &&
              envelopes[i][1] > envelopes[j][1]) {
            dp_h[i] = dp_h[j] + 1;
          } else {
            dp_h[i] = 1;
          }
        }
      }
    }

    int res = 0;
    for (auto i = 0; i < n; i++) {
      res = std::max(res, std::max(dp_w[i], dp_h[i]));
    }
    return res;
  }
};
