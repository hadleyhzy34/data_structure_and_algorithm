#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> grayCode(int n) {}

  void backtrack(int cur, std::vector<int> &visited, int cnt) {
    if (cnt == visited.size()) {
    }
    visited[cur] = 1;
    for (int i = 0; i < n; i++) {
      if ((cur >> i) & 1) {
        cur = cur;
        if (visited[cur] == 0) {
          backtrack(cur, visited, cnt + 1);
        }
      }
    }
  }

private:
  std::vector<int> res;
};
