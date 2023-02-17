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
    int countUnivalSubtrees(TreeNode* root) {
        if(!root){
            return 0;
        }
        int total = 0;
        countUS(root, &total);
        return total;
    }

    bool countUS(TreeNode* node, int* total){
        if(!node->left&&!node->right){
            *total += 1;
            std::cout<<node->val<<" "<<(*total)<<std::endl;
            return true;
        }
        bool tmp = true;
        if(node->left){
            if(countUS(node->left,total)&&node->left->val == node->val){
                tmp = true;
            }else{
                tmp = false;
            }
        }
        
        if(node->right){
            if(countUS(node->right, total)&&node->right->val == node->val){
                tmp = tmp&&true;
            }else{
                tmp = false;
            }
        }
        if(tmp){
            // std::cout<<"parent node: "<<node->val<<" "<<(*total)<<" "<<node->right->val<<std::endl;
            *total += 1;
        }
        return tmp;
    }
};;
