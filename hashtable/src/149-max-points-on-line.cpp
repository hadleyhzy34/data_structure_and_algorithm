#include <cfloat>
#include <iostream>
#include <numeric>
#include <unordered_map>

int gcd(int a, int b) {
  if (a == 0) {
    return b;
  } else if (b == 0) {
    return a;
  } else if (a == b) {
    return a;
  } else if (a > b) {
    return gcd(a - b, b);
  } else {
    return gcd(a, b - a);
  }
}

class Solution {
public:
  int maxPoints(std::vector<std::vector<int>> &points) {
    int res = 0;
    int n = points.size();
    std::unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) {
      int x1 = points[i][0];
      int y1 = points[i][1];
      for (int j = i + 1; j < n; j++) {
        int x = points[i][0] - points[j][1];
        int y = points[i][1] - points[j][1];
        if (x == 0) {
          y = 0;
        } else if (y == 0) {
          x = 0;
        } else {
          if (y < 0) {
            y = -y;
            x = -x;
          }
          int gcdXY = gcd(abs(x), abs(y));
          x /= gcdXY;
          y /= gcdXY;
        }
        umap[y + 2e5 * x]++;
      }
      for (auto &[k, v] : umap) {
        res = std::max(res, umap[k]);
      }
    }
  }
};
