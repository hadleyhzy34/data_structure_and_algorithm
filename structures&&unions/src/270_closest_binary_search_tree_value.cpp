#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
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
    int closestValue(TreeNode* root, double target){
        int res = INT_MAX;
        dfs(root, target, &res);
        return res;
    }
    
    void dfs(TreeNode* node, double target, int* closest_value){
        if(node == NULL){
            return;
        }
        if(node->val == target){
            *closest_value = node->val;
            return;
        }else if(std::fabs(target - node->val) < std::fabs(*closest_value - target)){
            // std::cout<<node->val<<" "<<target<<" "<<std::fabs(target - node->val)<<std::endl;
            *closest_value = node->val;
        }

        if(node->val < target){
            dfs(node->right, target, closest_value);
        }else{
            dfs(node->left, target, closest_value);
        }
    }
};
