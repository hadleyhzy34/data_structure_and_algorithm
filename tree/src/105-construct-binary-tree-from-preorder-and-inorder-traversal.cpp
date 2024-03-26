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
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (preorder.size() == 0) {
      return nullptr;
    }
    int n = preorder.size();
    TreeNode *root = dfs(preorder, 0, n - 1, inorder, 0, n - 1);
    return root;
  }

  TreeNode *dfs(std::vector<int> &preorder, int pl, int pr,
                std::vector<int> &inorder, int il, int ir) {
    if (preorder.empty()) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[pl]);

    int cntLeft = 0;
    for (auto i = il; i <= ir; i++) {
      if (inorder[i] == root->val) {
        break;
      } else {
        cntLeft++;
      }
    }
    if (cntLeft > 0) {
      root->left =
          dfs(preorder, pl + 1, pl + cntLeft, inorder, il, il + cntLeft - 1);
    }
    if (pl + cntLeft < pr) {
      root->right =
          dfs(preorder, pl + cntLeft + 1, pr, inorder, il + cntLeft + 1, ir);
    }
    return root;
  }
};
