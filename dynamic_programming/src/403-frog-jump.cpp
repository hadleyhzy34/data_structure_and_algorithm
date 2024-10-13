#include <iostream>
#include <string.h>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool canCross(std::vector<int> &stones) {
    int n = stones.size();
    std::vector<std::unordered_set<int>> steps(n);
    steps[0].insert(stones[0]);
    for (int i = 1; i < stones.size(); i++) {
      if (i == 1) {
        if (stones[0] + 1 == stones[1]) {
          steps[1].insert(1);
        } else {
          return false;
        }
      } else {
        for (int j = 0; j < i; j++) {
          if (steps[j].count(stones[i] - stones[j] - 1)) {
            steps[i].insert(stones[i] - stones[j]);
            if (i == n - 1) {
              return true;
            }
          } else if (steps[j].count(stones[i] - stones[j] + 1)) {
            steps[i].insert(stones[i] - stones[j]);
            if (i == n - 1) {
              return true;
            }
          } else if (steps[j].count(stones[i] - stones[j])) {
            steps[i].insert(stones[i] - stones[j]);
            if (i == n - 1) {
              return true;
            }
          }
        }
      }
    }
    return false;
  }
};
