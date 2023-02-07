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
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        std::string tmp = "";
        checkPath(root, tmp, res);
        return res;
    }
    void checkPath(TreeNode* node, std::string curString, std::vector<std::string>& res){
        if(node == NULL){
            return;
        }
        // curString += "->";
        curString += std::to_string(node->val);
        if(node->left == NULL && node->right == NULL){
            res.push_back(curString);
        }else{
            curString += "->";
        }
        checkPath(node->left, curString, res);
        checkPath(node->right, curString, res);
    }
};
