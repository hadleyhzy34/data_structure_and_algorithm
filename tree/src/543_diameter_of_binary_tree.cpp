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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxDepth(root, 0, &res);
        return res;
    }
    
    int maxDepth(TreeNode* node, int cur_depth, int* max_depth){
        if(node == NULL){
            return 0;
        }
        int left_depth = 0;
        int right_depth = 0;
        if(node->left){
            left_depth = maxDepth(node->left, cur_depth + 1, max_depth);
            left_depth += 1;
        }
        if(node->right){
            right_depth = maxDepth(node->right, cur_depth + 1, max_depth);
            right_depth += 1;
        }
        if(left_depth + right_depth > *max_depth){
            // std::cout<<node->val<<" "<<left_depth<<" "<<right_depth<<std::endl;
            *max_depth = left_depth + right_depth;
        }
        return std::max(left_depth,right_depth);
    }
};
