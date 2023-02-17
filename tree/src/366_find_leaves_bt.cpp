#include <iostream>
#include <vector>
#include <unordered_map>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<std::vector<int>> findLeaves(TreeNode* root) {
        std::vector<std::vector<int>> res;
        checkDepth(root, res);
        return res;
    }

    int checkDepth(TreeNode* node, std::vector<std::vector<int>>& res){
        if(!node->left&&!node->right){
            if(res.empty()){
                res.push_back({node->val});
            }else{
                res[0].push_back(node->val);
            }
            return 1;
        }
        int l_depth=0, r_depth=0;
        if(node->left){
            l_depth = checkDepth(node->left, res);
        }
        if(node->right){
            r_depth = checkDepth(node->right, res);
        }

        int depth = std::max(l_depth,r_depth)+1;

        if(res.size()<depth){
            res.push_back({node->val});
        }else{
            res[depth-1].push_back(node->val);
        }
        return depth;
    }
};
