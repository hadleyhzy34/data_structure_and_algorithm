#include <iostream>
#include <string.h>
#include <vector>

typedef std::vector<std::vector<int>> matrice;
class NumMatrix {
public:
  NumMatrix(matrice &matrix) {
    m = matrix.size();
    n = matrix[0].size();
    this->matrix = matrix;
    rows = std::vector<int>(4 * m, 0);
    cols = std::vector<int>(4 * n, 0);
    preRows = std::vector<int>(m, 0);
    preCols = std::vector<int>(n, 0);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        preRows[i] += matrix[i][j];
        preCols[j] += matrix[i][j];
      }
    }
    build(rows, preRows, 1, 0, m - 1);
    build(cols, preCols, 1, 0, n - 1);
  }

  void build(std::vector<int> &tree, std::vector<int> &nums, int idx, int l,
             int r) {
    if (l == r) {
      tree[idx] = nums[l];
    } else {
      int m = (l + r) / 2;
      build(tree, nums, 2 * idx, l, m);
      build(tree, nums, 2 * idx + 1, m + 1, r);
      tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
  }

  void update(int col, int row, int val) {
    int c = val - matrix[row][col];
    matrix[row][col] = val;
  }

  void update(std::vector<int> &arr, int nIdx, int l, int r, int idx, int val) {
    if (l == r) {
      arr[nIdx] += val;
    } else {
      int m = (l + r) / 2;
      if (l <= idx && idx <= m) {
        update(arr, nIdx * 2, l, m, idx, val);
      } else {
        update(arr, nIdx * 2 + 1, m + 1, r, idx, val);
      }
      arr[nIdx] = arr[nIdx * 2] + arr[nIdx * 2 + 1];
    }
  }

  int sumRange(int left, int right) {
    return sumRange(arr, 1, 0, n - 1, left, right);
  }

  int sumRange(std::vector<int> &arr, int nIdx, int l, int r, int left,
               int right) {
    if (l > right || r < left) {
      return 0;
    }
    if (l >= left && r <= right) {
      return arr[nIdx];
    }
    int m = (l + r) / 2;
    return sumRange(arr, nIdx * 2, l, m, left, right) +
           sumRange(arr, nIdx * 2 + 1, m + 1, r, left, right);
  }

private:
  std::vector<int> rows;
  std::vector<int> cols;
  std::vector<int> preRows;
  std::vector<int> preCols;
  matrice matrix;
  int m, n;
};
