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
    
    int sumNumbers(TreeNode* root) {
        int curSum = 0;
        int total = 0;
        sumNode(root, curSum, &total);
        return total;
    }
    
    void sumNode(TreeNode* node, int curSum, int* total){
        if(node->left == NULL && node->right == NULL){
            *total += curSum * 10 + node->val;
            return;
        }
        if(node->left){
            sumNode(node->left, curSum * 10 + node->val);
        }
        if(node->right){
            sumNode(node->right, curSum * 10+ node->val);
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
