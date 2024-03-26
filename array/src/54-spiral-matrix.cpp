#include <iostream>
#include <vector>
typedef std::vector<std::vector<int>> matrice;

class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    matrice visited(m, std::vector<int>(n, 0));

    int i = 0;
    int j = 0;
    int depth = 0;
    std::vector<int> res;
    while (true) {
      if (visited[i][j] == 0) {
        res.push_back(matrix[i][j]);
        visited[i][j] = 1;
      }
      if (j + 1 < n && visited[i][j + 1] == 0 &&
          (i == depth || m - 1 - i == depth || j + 1 == depth ||
           n - 1 - (j + 1) == depth)) {
        j++;
      } else if (i < m - 1 && visited[i + 1][j] == 0 &&
                 (j == depth || n - 1 - j == depth || (i + 1) == depth ||
                  m - 1 - (i + 1) == depth)) {
        i++;
      } else if (j > 0 && visited[i][j - 1] == 0 &&
                 (i == depth || m - 1 - i == depth || (j - 1) == depth ||
                  n - 1 - (j - 1) == depth)) {
        j--;
      } else if (i > 0 && visited[i - 1][j] == 0 &&
                 (j == depth || n - 1 - j == depth || (i - 1) == depth ||
                  m - 1 - (i - 1) == depth)) {
        i--;
      } else {
        depth++;
        if (depth >= std::max(m, n) / 2 + 1) {
          break;
        }
      }
    }
    return res;
  }
};
