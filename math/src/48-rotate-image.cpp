#include <iostream>
#include <string.h>
#include <vector>

typedef std::vector<std::vector<int>> mat;

void rotate(mat &matrix) {
  int n = matrix.size();

  // transpose
  for (auto i = 0; i < n; i++) {
    for (auto j = i + 1; j < n; j++) {
      std::swap(matrix[i][j], matrix[j][i]);
    }
  }

  // flip matrix
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < n / 2; j++) {
      std::swap(matrix[i][j], matrix[i][n - j - 1]);
    }
  }
}
