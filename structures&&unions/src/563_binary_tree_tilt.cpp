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
    int findTilt(TreeNode* root) {
        std::vector<int> ret;
        returnSum(root, ret);
        int res = 0;
        for(auto r:ret){
            res += r;
        }
        return res;
    }

    int returnSum(TreeNode* node, std::vector<int>& res){
        if(node == nullptr){
            return 0;
        }
        int sumLeft = 0;
        if(node->left){
            sumLeft = returnSum(node->left, res);
        }
        int sumRight = 0;
        if(node->right){
            sumRight = returnSum(node->right, res);
        }
        res.push_back(std::abs(sumLeft - sumRight));
        return sumLeft + sumRight + node->val;
    }
};
