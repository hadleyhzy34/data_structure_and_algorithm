#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

void dfs(TreeNode *node, int wSum, int oSum, int &res) {
  if (!node) {
    return;
  }

  oSum = std::max(wSum, oSum);
  wSum = oSum + node->val;

  if (res < std::max(oSum, wSum)) {
    res = std::max(oSum, wSum);
  }

  if (node->left) {
    dfs(node->left, wSum, oSum, res);
  }

  if (node->right) {
    dfs(node->right, wSum, oSum, res);
  }
}

int rob(TreeNode *root) {
  int res = 0;
  dfs(root, 0, 0, res);
  return res;
}
