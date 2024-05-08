#include <climits>
#include <iostream>
#include <stack>
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

class Codec {
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode *root) {
    if (!root)
      return "";
    dfs(root);
    return res;
  }

  void dfs(TreeNode *node) {
    res += std::to_string(node->val);
    if (!node->left && !node->right) {
      return;
    }
    if (node->left) {
      res.push_back('(');
      dfs(node->left);
      res.push_back(')');
    } else {
      res += "(-)";
    }

    if (node->right) {
      res.push_back('(');
      dfs(node->right);
      res.push_back(')');
    }
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(std::string data) {
    std::stack<TreeNode *> st;
    // bool right = false;
    for (auto i = 0; i < data.length(); i++) {
      if (i == 0 || data[i] == '(') {
        int cur = 0;
        if (data[i] == '(')
          i++;
        if (data[i] == '-') {
          st.push(nullptr);
        } else {
          while (i < data.length() && std::isdigit(data[i])) {
            cur = cur * 10 + data[i] - '0';
            i++;
          }
          i--;
          TreeNode *node = new TreeNode(cur);
          st.push(node);
        }
      } else if (data[i] == ')') {
        TreeNode *tmp = st.top();
        st.pop();
        if (!st.empty()) {
          if (!tmp) {
            TreeNode *node = new TreeNode(-1);
            st.top()->left = node;
          } else {
            if (st.top()->left) {
              st.top()->right = tmp;
            } else {
              st.top()->left = tmp;
            }
          }
        }
      }
    }
    if (st.empty()) {
      return nullptr;
    } else {
      reset(st.top());
      return st.top();
    }
  }

  void reset(TreeNode *node) {
    if (!node) {
      return;
    }
    if (node->left) {
      if (node->left->val < 0) {
        node->left = nullptr;
      } else {
        reset(node->left);
      }
    }
    if (node->right) {
      reset(node->right);
    }
  }

private:
  std::string res = "";
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
class Solution {
public:
  void recoverTree(TreeNode *root) {
    int cur = INT_MIN;
    dfs(root, nullptr);
  }

  // return rightmost leaf node given current node
  // return previous node in sequence
  void dfs(TreeNode *node, TreeNode *cur) {
    if (node->left) {
      dfs(node->left, cur);
    }
    if (cur && node->val < cur->val) {
      std::swap(node->val, cur->val);
    }
    if (node->right) {
      dfs(node->right, cur);
    }
  }

private:
  TreeNode *pre = nullptr;
};
