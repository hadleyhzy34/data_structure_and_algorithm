#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *sortedArrayToBST(std::vector<int> &nums) {
    if (nums.empty()) {
      return nullptr;
    }
    return dfs(nums, 0, nums.size() - 1);
  }

  TreeNode *dfs(std::vector<int> &nums, int l, int r) {
    if (l > r) {
      return nullptr;
    }
    int m = (l + r) / 2;
    TreeNode *node = new TreeNode(nums[m]);
    if (l < m) {
      node->left = dfs(nums, l, m - 1);
    }
    if (m < r) {
      node->right = dfs(nums, m + 1, r);
    }
    return node;
  }
};
