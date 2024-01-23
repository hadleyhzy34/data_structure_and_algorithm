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
    void flatten(TreeNode* root) {
        std::vector<TreeNode*> list;
        preOrder(root, list);
        if(!root){
            return;
        }
        for(int i=0;i<list.size()-1;i++){
            list[i]->left = nullptr;
            list[i]->right = list[i+1];
        }
    }

    void preOrder(TreeNode* node, vector<TreeNode*> &list){
        if(!node){
            return;
        }
        list.push_back(node);
        preOrder(node->left, list);
        preOrder(node->right, list);
    }
};
