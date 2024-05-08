#include <cctype>
#include <cstddef>
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode *root) {
    dfs(root);
    return res;
  }

  void dfs(TreeNode *node) {
    res += std::to_string(node->val);
    if (node->left) {
      res.push_back('(');
      dfs(node->left);
      res.push_back(')');
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
    for (auto i = 0; i < data.length(); i++) {
      if (std::isdigit(data[i])) {
        int cur = 0;
        while (i < data.length() && std::isdigit(data[i])) {
          cur = cur * 10 + data[i] - '0';
          i++;
        }
        TreeNode *node = new TreeNode(cur);
        st.push(node);
        if (st.empty()) {
          st.push(node);
        } else {
          if (st.top()->left) {
            st.top()->right = node;
          } else {
            st.top()->left = node;
          }
        }
      } else if (data[i] == ')') {
        TreeNode *tmp = st.top();
        st.pop();
        if (st.top()->left) {
          st.top()->right = tmp;
        } else {
          st.top()->left = tmp;
        }
      }
    }
    return st.top();
  }

private:
  std::string res = "";
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
