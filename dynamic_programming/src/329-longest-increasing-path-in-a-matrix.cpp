#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

typedef std::vector<std::vector<int>> matrice;

class Solution {
public:
  int longestIncreasingPath(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int res = 1;
    for (auto i = 0; i < m; i++) {
      for (auto j = 0; j < n; j++) {
        if (i > 0 && matrix[i][j] > matrix[i - 1][j]) {
          continue;
        }
        if (i < m - 1 && matrix[i][j] > matrix[i + 1][j]) {
          continue;
        }
        if (j > 0 && matrix[i][j] > matrix[i][j - 1]) {
          continue;
        }
        if (j < n - 1 && matrix[i][j] > matrix[i][j + 1]) {
          continue;
        }
        int depth = dfs(matrix, m, n, i, j);
        res = std::max(res, depth);
      }
    }

    return res;
  }

  int dfs(matrice &matrix, int m, int n, int i, int j) {
    if (umap.count(1000 * i + j)) {
      return umap[1000 * i + j];
    }
    int l = 0;
    if (j > 0 && matrix[i][j - 1] > matrix[i][j]) {
      l = dfs(matrix, m, n, i, j - 1);
    }

    int r = 0;
    if (j < n - 1 && matrix[i][j + 1] > matrix[i][j]) {
      r = dfs(matrix, m, n, i, j + 1);
    }

    int u = 0;
    if (i > 0 && matrix[i + 1][j] > matrix[i][j]) {
      u = dfs(matrix, m, n, i + 1, j);
    }

    int d = 0;
    if (i < m - 1 && matrix[i + 1][j] > matrix[i][j]) {
      d = dfs(matrix, m, n, i + 1, j);
    }

    int depth = l + r + u + d;
    umap[1000 * i + j] = depth;
    return depth;
  }

private:
  std::unordered_map<int, int> umap;
};
