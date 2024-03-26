#include <iostream>
#include <vector>

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
  void recoverTree(TreeNode *root) { dfs(root, nullptr, nullptr); }
  TreeNode *dfs(TreeNode *node, TreeNode *left, TreeNode *right) {
    if (left && left->val > node->val) {
      std::swap(left->val, node->val);
    }
    if (right && right->val < node->val) {
      std::swap(right->val, node->val);
    }
    if (node->left) {
      dfs(node->left, nullptr, node);
    }
    if (node->right) {
      dfs(node->right, node, nullptr);
    }
  }
};
