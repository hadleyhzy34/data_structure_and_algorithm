#include <cctype>
#include <iostream>
#include <stack>
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
  TreeNode *str2tree(std::string s) {
    std::stack<TreeNode *> snode;
    int i = 0;
    while (i < s.length()) {
      if (s[i] == '(') {
        int cur = 0;
        while (i < s.length() && std::isdigit(s[i])) {
          cur = cur * 10 + s[i] - '0';
          i++;
        }
        sval.push(cur);
        snode.push(new TreeNode(cur));
      } else if (s[i] == ')') {
        TreeNode *tmp = snode.top();
        snode.pop();
        if (snode.top()->left) {
          snode.top()->right = tmp;
        } else {
          snode.top()->left = tmp;
        }
      }
    }
    return snode.top();
  }
};
