#include <iostream>
#include <string.h>
#include <vector>

// The knows API is defined for you.
bool knows(int a, int b);

class Solution {
public:
  int findCelebrity(int n) {
    std::vector<int> visited(n + 1, 0);
    for (auto i = 0; i < n; i++) {
      if (visited[i] == 1)
        continue;
      for (int j = 0; j < n; j++) {
        if (i == j) {
          continue;
        } else {
          if (knows(j, i)) {
            visited[j] = 1;
          } else {
            visited[i] = 1;
            break;
          }
        }
      }
      if (visited[i] == 0) {
        return i;
      }
    }
    return -1;
  }
};
