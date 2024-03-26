#include <iostream>
#include <string.h>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool canMeasureWater(int x, int y, int target) {
    return dfs(x, y, 0, 0, target);
  }

  bool dfs(int x, int y, int x1, int y1, int target) {
    if (uset.count(1000 * x1 + y1)) {
      return false;
    }

    if (x1 + y1 == target) {
      return true;
    }
    uset.insert(1000 * x1 + y1);
    bool a = dfs(x, y, x, y1, target);
    bool b = dfs(x, y, x1, y, target);
    bool c = dfs(x, y, 0, y1, target);
    bool d = dfs(x, y, x1, 0, target);
    bool e = dfs(x, y, std::min(x1 + y1, x), (x1 + y1 > x) ? x1 + y1 - x : 0,
                 target);
    bool f = dfs(x, y, std::min(x1 + y1, y), (x1 + y1 > y) ? x1 + y1 - y : 0,
                 target);

    return a || b || c || d || e || f;
  }

private:
  std::unordered_set<int> uset;
};
