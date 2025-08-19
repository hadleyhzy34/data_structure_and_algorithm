#include <climits>
#include <iostream>

class Solution {
public:
  bool find132pattern(std::vector<int> &nums) {
    int n = nums.size();
    if (n <= 2)
      return false;
    std::stack<int> st;
    int third = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
      if (st.empty()) {
        st.push(nums[i]);
      } else {
        if (nums[i] < third) {
          std::cout << nums[i] << st.top() << third << std::endl;
          return true;
        } else if (nums[i] > third) {
          while (!st.empty() && nums[i] > st.top()) {
            third = st.top();
            st.pop();
          }
          st.push(nums[i]);
        }
        // else if (nums[i] < st.top() && third == INT_MIN) {
        //   st.push(nums[i]);
        // }
        // else if (nums[i] < st.top()) {
        //   third = nums[i];
        // }
      }
    }
    return false;
  }
};

int main() {
  // std::vector<int> input = {1, 2, 3, 4};
  // std::vector<int> input = {-2, 1, 1, -2, 1, 1};
  std::vector<int> input = {0, 1, 2, 0, 1, 2, 0};
  Solution sol;
  sol.find132pattern(input);
  return 0;
}
