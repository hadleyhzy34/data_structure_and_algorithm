#include <iostream>
#include <utility>
#include <vector>

typedef std::vector<std::vector<int>> matrice;
class Solution {
public:
  int kthSmallest(std::vector<std::vector<int>> &matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();

    int s = matrix[0][0];
    int l = matrix[m - 1][n - 1];
    while (s < l) {
      int m = s + (l - s) / 2;
      int cnt = countLQ(matrix, m);
      if (k == cnt) {
        return m;
      } else if (k < cnt) {
        l = m;
      } else {
        s = m + 1;
      }
    }
    return s;
  }

  int countLQ(matrice &matrix, int val) {
    int cnt = 0;

    int rdx = matrix.size() - 1;
    int cdx = 0;

    while (rdx >= 0) {
      if (matrix[rdx][cdx] <= val) {
        if (cdx == matrix[rdx].size() - 1) {
          rdx--;
        } else {
          cdx++;
        }
      } else {
        cnt += cdx;
        rdx--;
      }
    }

    return cnt;
  }
};
