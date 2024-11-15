#include <iostream>

struct biNum {
  int digit;
  biNum *children[2];
  biNum() {
    digit = 0;
    children[0] = nullptr;
    children[1] = nullptr;
  }
};

class Solution {
public:
  biNum *root = new biNum();
  int findMaximumXOR(std::vector<int> &nums) {
    for (auto num : nums) {
      build(root, num);
    }
    for (auto num : nums) {
      dfs(root, num);
    }
    return res;
  }

private:
  void build(biNum *node, int num) {
    for (int i = 31; i >= 0; i--) {
      if ((num >> i) & 1) {
        if (!node->children[1]) {
          node->children[1] = new biNum();
        }
        node = node->children[1];
      } else {
        if (!node->children[0]) {
          node->children[0] = new biNum();
        }
        node = node->children[0];
      }
    }
  }

  int dfs(biNum *node, int num) {
    int cur = 0;
    for (int i = 31; i >= 0; i--) {
      int t = (num>>i)&1;
      if (node->children[0] && node->children[1]) {
        if (t == 0) {
          node = node->children[1];
        } else {
          node = node->children[0];
        }
        cur |= (1 << i);
      } else if (node->children[0] || node->children[1]) {
        if (node->children[0]) {
          cur |= (t<<i);
          node = node->children[0];
        } else {
          cur |= ((1-t)<<i);
          node = node->children[1];
        }
      }
      std::cout<<i<<" "<<cur<<std::endl;
    }
    res = std::max(res, cur);
    return res;
  }

private:
  int res = 0;
};

int main() {
    Solution solution;

    // Test case 1
    std::vector<int> nums1 = {3, 10, 5, 25, 2, 8};
    std::cout << "Maximum XOR of Test Case 1: " << solution.findMaximumXOR(nums1) << std::endl;

    // Test case 2
    std::vector<int> nums2 = {8, 1, 2, 12, 7, 6};
    std::cout << "Maximum XOR of Test Case 2: " << solution.findMaximumXOR(nums2) << std::endl;

    // Test case 3
    std::vector<int> nums3 = {4, 6, 7};
    std::cout << "Maximum XOR of Test Case 3: " << solution.findMaximumXOR(nums3) << std::endl;

    // Test case 4
    std::vector<int> nums4 = {0};
    std::cout << "Maximum XOR of Test Case 4: " << solution.findMaximumXOR(nums4) << std::endl;

    return 0;
}