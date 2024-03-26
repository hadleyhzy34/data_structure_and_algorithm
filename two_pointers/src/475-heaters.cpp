#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <vector>

class Solution {
public:
  int findRadius(std::vector<int> &houses, std::vector<int> &heaters) {
    int rPtr = 0;
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());

    int maxDist = 0;
    for (auto i = 0; i < houses.size(); i++) {
      while (rPtr != heaters.size() - 1 ||
             houses[i] - heaters[rPtr] > houses[i] - heaters[rPtr + 1]) {
        rPtr++;
      }
      maxDist = std::max(maxDist, houses[i] - heaters[rPtr]);
    }
    return maxDist;
  }
};
