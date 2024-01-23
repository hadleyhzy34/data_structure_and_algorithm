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
    int longestConsecutive(TreeNode* root) {
        int res = 1;
        checkConsecutive(root, 1, &res);
        return res;
    }

    void checkConsecutive(TreeNode* node, int len, int* largest){
        if(!node){
            return;
        }
        if(len > *largest){
            *largest = len;
        }

        // std::cout<<node->val<<" "<<node->right->val<<" "<<len<<std::endl;

        if(node->left){
            if((node->left->val-node->val)==1){
                checkConsecutive(node->left, len+1, largest);
            }else{
                checkConsecutive(node->left, 1, largest);
            }
        }

        if(node->right){
            if((node->right->val-node->val)==1){
                checkConsecutive(node->right, len+1, largest);
            }else{
                checkConsecutive(node->right, 1, largest);
            }
        }
    }
};
