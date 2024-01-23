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
    void printInorder(TreeNode* node, std::vector<int>& res){
        if(node == NULL){
            return;
        }
        printInorder(node->left, res);
        res.push_back(node->val);
        printInorder(node->right, res);
    }

    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        printInorder(root, res);
        return res;
    }
};
