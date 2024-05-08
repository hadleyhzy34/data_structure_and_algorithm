// 310. Minimum Height Trees
#include <iostream>
#include <string.h>
#include <vector>

typedef std::vector<std::vector<int>> matrice;
class Solution {
public:
  std::vector<int> findMinHeightTrees(int n,
                                      std::vector<std::vector<int>> &edges) {
    matrice neighbor(n, std::vector<int>(n, 0));
    for (auto e : edges) {
      neighbor[e[0]][e[1]] = 1;
      neighbor[e[1]][e[0]] = 1;
    }
    std::vector<int> visited(n, 0);
    int maxLen = 0;
    dfs(neighbor, visited, 0, 0, 0, maxLen);
    int depth = maxLen / 2;
  }

  int dfsNode(matrice &neighbor, std::vector<int> &visited, int idx, int depth,
              int &maxLen) {
    if (visited[idx]) {
      return 0;
    }
    visited[idx] = 1;
    int res = 1;
    int len1 = depth;
    int len2 = 0;
    for (auto i = 0; i < neighbor[idx].size(); i++) {
      if (neighbor[idx][i] && visited[i] == 0) {
        int cur = 1 + dfs(neighbor, visited, i, root, depth + 1, maxLen);
        if (cur > len1) {
          len2 = len1;
          len1 = cur;
        } else if (cur > len2) {
          len2 = cur;
        }
        res = std::max(res, len1 + len2);
        if (res > maxLen) {
          node = idx;
          maxLen = res;
        }
      }
    }
    return len1;
  }

  int dfsMaxLen(matrice &neighbor, std::vector<int> &visited, int idx, int root,
                int depth, int &maxLen) {
    if (visited[idx]) {
      return 0;
    }
    visited[idx] = 1;
    int res = 1;
    int len1 = depth;
    int xx = root;
    int len2 = 0;
    int yy = idx;
    for (auto i = 0; i < neighbor[idx].size(); i++) {
      if (neighbor[idx][i] && visited[i] == 0) {
        int cur = 1 + dfsMaxLen(neighbor, visited, i, root, depth + 1, maxLen);
        if (cur > len1) {
          len2 = len1;
          yy = xx;
          len1 = cur;
          xx = i;
        } else if (cur > len2) {
          len2 = cur;
          yy = i;
        }
        res = std::max(res, len1 + len2);
        if (res > maxLen) {
          x = xx;
          y = yy;
          maxLen = res;
        }
      }
    }
    return len1;
  }

private:
  int x;
  int y;
  int node;
};
