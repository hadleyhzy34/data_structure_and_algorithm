#include <iostream>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

std::vector<int> dfs(TreeNode *node, bool toRob, int &res) {
  if (!node) {
    return {0, 0};
  }

  int robbed = node->val;
  int notRobbed = 0;

  if (node->left) {
    std::vector<int> tmp = dfs(node->left, false, res);
    robbed += tmp[0];
    notRobbed += tmp[1];
  }

  if (node->right) {
    std::vector<int> tmp = dfs(node->right, false, res);
    robbed += tmp[0];
    notRobbed += tmp[1];
  }

  int cur = std::max(robbed, notRobbed);
  res = std::max(res, cur);

  if (toRob) {
    return {robbed, cur};
  } else {
    return {notRobbed, cur};
  }
}

int rob(TreeNode *root) {
  int res = 0;
  dfs(root, true, res);
  return res;
}
