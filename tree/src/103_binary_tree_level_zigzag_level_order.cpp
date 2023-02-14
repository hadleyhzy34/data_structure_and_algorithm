#include <iostream>
#include <vector>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if(root==nullptr){
            return {};
        }
        preOrder(root, res, 0, true);
        return res;
    }

    void preOrder(TreeNode* node, std::vector<std::vector<int>> &res, int depth, bool left){
        if(res.size() <= depth){
            res.emplace_back(std::vector<int>{node->val});
        }else{
            if(left){
                res[depth].emplace_back(node->val);
            }else{
                res[depth].insert(res[depth].begin(),node->val);
            }
        }
        if(node->left){
            preOrder(node->left, res, depth+1, !left);
        }
        if(node->right){
            preOrder(node->right, res, depth+1, !left);
        }
    }
};
