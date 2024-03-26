#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

class Solution {
public:
  int kthSmallest(std::vector<std::vector<int>> &matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    int kk = std::sqrt(k);
    if (kk * kk == k)
      return matrix[kk - 1][kk - 1];
    int cur = kk * kk;
    int l = 0;
    int d = 0;
    while (cur != k) {
      if (matrix[kk][l] <= matrix[d][kk]) {
        l++;
        cur++;
      } else {
        d++;
        cur++;
      }
    }
    return std::min(matrix[kk][l], matrix[d][kk]);
  }
};
