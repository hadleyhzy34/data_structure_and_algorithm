#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        if(root->left){
            if(!isBalanced(root->left)){
                return false;
            }
        }
        if(root->right){
            if(!isBalanced(root->right)){
                return false;
            }
        }
        if(std::abs(height(root->left) - height(root->right)) <= 1){
            return true;
        }else{
            return false;
        }
    }

    int height(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        return std::max(height(node->left), height(node->right)) + 1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        height(root, &res);
        return res;
    }

    int height(TreeNode* node, bool* res){
        if(node==NULL){
            return 0;
        }

        int l_h = height(node->left, res);
        int r_h = height(node->right, res);

        if(std::abs(l_h - r_h) > 1){
            *res = false;
        }
        return std::max(l_h, r_h) + 1;
    }
};
