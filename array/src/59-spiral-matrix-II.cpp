#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> matrice;

class Solution {
public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    matrice res(n, std::vector<int>(n, 0));
    int cur = 1;
    int l = 0;
    int r = n - 1;
    int u = 0;
    int d = n - 1;
    int i = 0;
    int j = 0;
    while (true) {
      for (j = l; j <= r; j++) {
        res[i][j] = (cur++);
      }
      if (++u > d)
        break;
      for (i = u; i <= d; i++) {
        res[i][j] = (cur++);
      }
      if (--r < l)
        break;
      for (j = r; j >= l; j--) {
        res[i][j] = (cur++);
      }
      if (--d < u)
        break;
      for (i = d; i >= u; i--) {
        res[i][j] = (cur++);
      }
      if (++l > r)
        break;
    }
    return res;
  }
};
