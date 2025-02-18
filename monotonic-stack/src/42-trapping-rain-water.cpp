#include <ios>
#include <iostream>
#include <utility>

class Solution {
public:
  int trap(std::vector<int> &height) {
    int res = 0;
    int n = height.size();

    // std::stack<std::pair<int, int>> st;
    // std::pair<int, int> curLargest = {-1, 0};

    std::stack<int> st;
    for (auto i = 0; i < n; i++) {
      if (st.empty()) {
        st.push(i);
      } else {
        // key part
        if (height[i] > height[st.top()]) {
          while (!st.empty() && height[i] > height[st.top()]) {
            int bottom = height[st.top()];
            st.pop();
            if (!st.empty()) {
              int w = i - st.top() - 1;
              int h = std::min(height[st.top()], height[i]) - bottom;
              res += w * h;
            }
          }
          st.push(i);
        } else {
          st.push(i);
        }
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << "Trapped Water: " << sol.trap(height)
            << std::endl; // Output should be 6
  return 0;
}
