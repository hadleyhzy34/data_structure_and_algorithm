#include <iostream>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int dp[desiredTotal + 1];
    for (auto i = 1; i <= std::min(maxChoosableInteger, desiredTotal); i++) {
      dp[i] = 1;
    }

    for (auto i = maxChoosableInteger + 1; i <= desiredTotal; i++) {
      bool cur = false;
      for (auto j = 1; j <= maxChoosableInteger; j++) {
        cur = cur || (!dp[i - j]);
        std::cout << i << " " << j << " " << cur << std::endl;
      }
      dp[i] = (cur == 1) ? 0 : 1;
    }
    return dp[desiredTotal];
  }
};

// dfs + memory
class Solution2 {
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal) {
      return false;
    }
    return dfs(0, 0, maxChoosableInteger, desiredTotal);
  }

  bool dfs(int bits, int cur, int maxChoosableInteger, int desiredTotal) {
    if (umap.find(bits) != umap.end()) {
      return umap[bits];
    }
    if (cur >= desiredTotal) {
      return true;
    }
    bool tmp = false;

    for (auto i = 1; i <= maxChoosableInteger; i++) {
      if (!(bits & (1 << i))) {
        if (cur + i >= desiredTotal) {
          tmp = true;
          break;
          // return true;
        } else {
          // as long as there's at least one dfs returned by next player that
          // they lose the game, you win the game tmp = tmp || (!dfs(bits | (1
          // << i), cur + i, maxChoosableInteger,
          //                desiredTotal));
          if (!dfs(bits | (1 << i), cur + i, maxChoosableInteger,
                   desiredTotal)) {
            tmp = true;
            break;
            //    return true;
          }
        }
      }
    }

    // std::cout<<cur<<" "<<tmp<<std::endl;
    umap[bits] = tmp;
    return tmp;
  }

private:
  std::unordered_map<int, bool> umap;
};
