#include <iostream>
#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void printPostorder(TreeNode* node, std::vector<int>& res){
        if(node == NULL){
            return;
        }
        printPostorder(node->left, res);
        printPostorder(node->right, res);
        res.push_back(node->val);
    }

    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        printPostorder(root, res);
        return res;
    }
};
