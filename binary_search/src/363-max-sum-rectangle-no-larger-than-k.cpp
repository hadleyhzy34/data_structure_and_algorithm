#include <climits>
#include <iostream>
#include <set>
#include <vector>
typedef std::vector<std::vector<int>> matrice;

class Solution {
public:
  int maxSumSubmatrix(std::vector<std::vector<int>> &matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    // int res = INT_MIN;

    // Optimize for wide matrices
    if (m > n) {
      std::swap(m, n);
      std::vector<std::vector<int>> transposed(m, std::vector<int>(n));
      for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++) {
          // std::cout<<i<<" "<<j<<" "<<matrix[i][j]<<std::endl;
          transposed[j][i] = matrix[i][j];
        }
      matrix.swap(transposed);
    }

    // m = matrix.size();
    // n = matrix[0].size();

    int res = -1e6;

    // prefix sum on every columns
    std::vector<int> columns(n, 0);

    // converting 2d into 1d, fixing rows
    for (int i = 0; i < m; i++) {
      //   std::vector<int> columns(n, 0);
      std::fill(columns.begin(), columns.end(), 0);
      for (int j = i; j < m; j++) {
        for (int col = 0; col < n; col++) {
          columns[col] += matrix[j][col];
        }
        res = std::max(res, maxSumK(columns, k));
        if (res == k)
          return res;
      }
    }

    return res;
  }

  int maxSumK(std::vector<int> &columns, int k) {
    int res = -1e6;
    std::set<int> sums;
    sums.insert(0);
    int preSum = 0;
    for (auto col : columns) {
      preSum += col;
      auto it = sums.lower_bound(preSum - k);
      if (it != sums.end()) {
        res = std::max(res, preSum - *it);
        if (res == k)
          return res;
      }
      sums.insert(preSum);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  // matrice array = {{1, 0, 1}, {0, -2, 3}};
  // matrice array = {{2, 2, -1}};
  matrice array = {{5, -4, -3, 4}, {-3, -4, 4, 5}, {5, 1, 5, -4}};
  // int k = 0;
  int k = 10;
  Solution sol;
  sol.maxSumSubmatrix(array, k);
  return 0;
}
