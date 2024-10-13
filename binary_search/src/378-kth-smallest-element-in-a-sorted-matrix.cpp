#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
class Solution {
public:
  int kthSmallest(std::vector<std::vector<int>> &matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int l = 0, r = cols - 1;
    int u = 0, d = rows - 1;
    bool turn = true;
    while (l <= r && u <= d) {
      if (turn) {
        int m = (l + r) / 2;
        int num1 = (m - l + 1) * (d - u + 1);
        int num2 = (r - m) * (d - u + 1);
        if (k == 1) {
          return matrix[l][u];
        } else if (k <= num1) {
          r = m;
        } else {
          k -= num1;
          l = m + 1;
        }
        turn = !turn;
      } else {
        int m = (u + d) / 2;
        int num1 = (m - u + 1) * (r - l + 1);
        int num2 = (d - m) * (r - l + 1);
        if (k == 1) {
          return matrix[l][u];
        } else if (k <= num1) {
          d = m;
        } else {
          k -= num1;
          u = m + 1;
        }
        turn = !turn;
      }
    }
    return 0;
  }
};
