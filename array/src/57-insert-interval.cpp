#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals,
                             vector<int> &newInterval) {
    std::vector<std::vector<int>> res;
    for (auto interval : intervals) {
      if (interval[0] < newInterval[0]) {
        res.push_back(interval);
      } else {
      }
    }
  }
};
