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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> res;
        lca(root,p,q,res);
        return res[0];
    }

    std::pair<bool,bool> lca(TreeNode* node, TreeNode* p, TreeNode* q, std::vector<TreeNode*>& res){
        if(!node){
            return pair(false,false);
        }
        bool l = (node->val==p->val);
        bool r = (node->val==q->val);

        auto [l_x, l_y] = lca(node->left, p, q, res);
        auto [r_x, r_y] = lca(node->right, p, q, res);

        if((l||l_x||r_x)&&(r||r_y||l_y)){
            res.push_back(node);
        }
        return std::pair(l||l_x||r_x,r||l_y||r_y);
    }
};
