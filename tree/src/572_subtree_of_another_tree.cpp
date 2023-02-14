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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isSameTree(root, subRoot)){
            return true;
        }
        if(root == NULL){
            return false;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* node, TreeNode* subNode){
        if(node==NULL&&subNode==NULL){
            return true;
        }else if(node == NULL || subNode == NULL){
            return false;
        }
        if(node->val != subNode->val){
            return false;
        }
        return isSameTree(node->left, subNode->left)&&isSameTree(node->right, subNode->right);
    }
};
