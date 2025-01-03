#include <iostream>
#include <set>
#include <string.h>
#include <unordered_set>
#include <vector>
typedef std::vector<std::vector<int>> matrice;

class Solution {
public:
  std::vector<std::vector<int>>
  outerTrees(std::vector<std::vector<int>> &trees) {
    int n = trees.size();
    // std::set<int> ures;
    matrice res;

    // sort points
    std::sort(trees.begin(), trees.end());

    // lower convex hull
    std::vector<std::vector<int>> lowerHull;
    for (auto &tree : trees) {
      if (lowerHull.size() < 2) {
        lowerHull.push_back(tree);
      } else {
        int n = lowerHull.size();
        while (n >= 2 &&
               crossProduct(lowerHull[n - 1], lowerHull[n - 2], tree) < 0) {
          lowerHull.pop_back();
          n--;
        }
        lowerHull.push_back(tree);
      }
    }

    int lowerSize = lowerHull.size();
    for (int i = trees.size() - 2; i >= 0; i--) {
      int n = lowerHull.size();
      while (n > lowerSize &&
             crossProduct(lowerHull[n - 1], lowerHull[n - 2], trees[i]) < 0) {
        lowerHull.pop_back();
        n--;
      }
      lowerHull.push_back(trees[i]);
    }

    // remove first duplicate points
    lowerHull.pop_back();

    return res;
  }

private:
  int crossProduct(std::vector<int> &a, std::vector<int> &b,
                   std::vector<int> &c) {
    //{cross product} = (x_2 - x_1)(y_3 - y_1) - (y_2 - y_1)(x_3 - x_1)
    return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
  }
};

class Solution1 {
public:
  std::vector<std::vector<int>>
  outerTrees(std::vector<std::vector<int>> &trees) {
    int n = trees.size();
    std::unordered_set<int> ures;
    matrice res;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        // two points represents a line based on ax+by+c=0 form
        //  a = y_2 - y_1
        //  b = -(x_2 - x_1)
        //  c = (x_2 - x_1)y_1 - (y_2 - y_1)x_1
        if (i == j) {
          continue;
        }
        int a = trees[j][1] - trees[i][1];
        int b = -(trees[j][0] - trees[i][0]);
        int c = (trees[j][0] - trees[i][0]) * trees[i][1] -
                (trees[j][1] - trees[i][1]) * trees[i][0];
        int sign = 0;
        bool check = true;
        for (int k = 0; k < n; k++) {
          if (k == i || k == j) {
            continue;
          }
          int t = (a * trees[k][0]) + (b * trees[k][1]) + c;
          if ((t * sign) >= 0) {
            if (t == 0) {
              sign = sign;
            } else {
              sign = (t > 0) ? 1 : -1;
            }
          } else {
            check = false;
            break;
          }
        }
        if (check) {
          ures.insert(1000 * trees[i][0] + trees[i][1]);
          ures.insert(1000 * trees[j][0] + trees[j][1]);
        }
      }
    }
    for (auto k : ures) {
      res.push_back({k / 1000, k % 1000});
    }
    return res;
  }
};
