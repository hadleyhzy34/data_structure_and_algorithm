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
    void printPreorder(TreeNode* node, std::vector<int>& res){
        if(node == NULL){
            return;
        }
        res.push_back(node->val);
        printPreorder(node->left, res);
        printPreorder(node->right, res);
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        printPreorder(root, res);
        return res;
    }
};
