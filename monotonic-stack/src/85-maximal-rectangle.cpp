#include <cstring>
#include <stack>
#include <vector>
typedef std::vector<std::vector<char>> matrice;

class Solution {
public:
  int maximalRectangle(std::vector<std::vector<char>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int res = 0;
    std::vector<int> heights(rows);
    for (int k = cols - 1; k >= 0; k--) {
      getBars(matrix, rows, cols, k, heights);
      res = std::max(res, largestRectangleArea(heights));
    }
    return res;
  }

  // get current array of bars starting from current cols
  void getBars(const matrice &matrix, int rows, int cols, int k,
               std::vector<int> &heights) {
    for (int i = 0; i < rows; i++) {
      //   heights[i] = 0;
      if (matrix[i][k] == '1') {
        heights[i] = heights[i] + 1;
      } else {
        heights[i] = 0;
      }
    }
  }

  int largestRectangleArea(std::vector<int> &heights) {
    int n = heights.size();

    int res = 0;

    std::stack<int> st;
    std::vector<int> l(n);
    std::vector<int> r(n, n);

    // find each index corresponding smaller height on its left side
    for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.top()] >= heights[i]) {
        r[st.top()] = heights[i];
        st.pop();
      }
      l[i] = (st.empty()) ? -1 : heights[st.top()];
      st.push(i);
    }

    for (int i = 0; i < n; i++) {
      res = std::max(res, heights[i] * ((r[i] - 1) - (l[i] + 1) + 1));
    }
    return res;
  }
};
