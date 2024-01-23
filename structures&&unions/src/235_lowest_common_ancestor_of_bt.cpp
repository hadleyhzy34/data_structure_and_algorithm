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
    //return lowest ancestor of p or q, at least one
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //preorder traversal, if current root is equal to either one of p or q, then it must be lca
        if(root==q||root==p){
            return root;
        }
        if(!root){
            return NULL;
        }
        TreeNode* l_node = lowestCommonAncestor(root->left, p, q);
        TreeNode* r_node = lowestCommonAncestor(root->right, p, q);
        //core idea, if l_node is la(lowest ancestor) of either p or q and r_node is la of either p or q, then l_node must be la of either p or q and r_node must be lca of the other one, then current root node must be lca of both.
        if(l_node&&r_node){
            return root;
        }else if(!l_node){
            return r_node;
        }else{
            return l_node;
        }
        // return NULL;
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
