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
  void recoverTree(TreeNode *root) { dfs(root); }

  // return rightmost leaf node given current node
  // return previous node in sequence
  TreeNode *dfs(TreeNode *node) {
    if (node->left) {
      TreeNode *pre = dfs(node->left);
      while (pre && node->val < pre->val) {
        std::swap(node->val, pre->val);
        dfs(node->left);
      }
    }
    TreeNode *r = node;
    if (node->right) {
      r = dfs(node->right);
    }
    return r;
  }

private:
  TreeNode *pre = nullptr;
};
