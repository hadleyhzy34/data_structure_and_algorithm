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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        inorder(root, 1, &depth);
        return depth;
    }

    void inorder(TreeNode* node, int curHeight, int* maxDepth){
        if(node == NULL){
            return;
        }
        inorder(node->left, curHeight+1, maxDepth);
        inorder(node->right, curHeight+1, maxDepth);
        if(curHeight > (*maxDepth)){
            *maxDepth = curHeight;
        }
    }
};

