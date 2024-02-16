/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<TreeNode *> generateTrees(int n) {
    for (auto l = 1; l <= n; l++) {
      for (auto j = 1; j + l - 1 <= n; j++) {
        if (l == 1) {
          nodeMap[j].push_back(new TreeNode(j));
        }
      }
    }
  }

private:
  std::vector<TreeNode *> nodes;
  std::unordered_map<int, std::vector<TreeNode *>> nodeMap;
};
