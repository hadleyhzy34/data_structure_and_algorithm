#include <iostream>
#include <string.h>
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
  TreeNode *deleteNode(TreeNode *root, int key) {
    dfs(root, key, nullptr, true);
    return root;
  }

  void dfs(TreeNode *node, int key) {
    if (node->val < key && node->right) {
      if (node->right->val == key) {
        node->right->
      } else {
        dfs(node->right, key);
      }
    } else if (node->val > key && node->left) {
      if (node->left->val == key) {
        node->left = sDfs(node->left, node->left);
      }
    }
  }

  int rightMost(TreeNode *node, TreeNode *root) {
    if (node->left) {
      if (node->left->left) {
        return rightMost(node->left);
      } else {
        int tmp = node->left->val;
        node->left = nullptr;
        return tmp;
      }
    } else {
      return node->val;
    }
  }
};
