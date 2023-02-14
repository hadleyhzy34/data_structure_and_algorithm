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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return gan2BST(nums);
    }

    TreeNode* gan2BST(std::vector<int>& nums){
        if(nums.empty()){
            return NULL;
        }
        TreeNode* root = new TreeNode;
        int len = nums.size();
        
        root->val = nums[len/2];
        // std::cout<<root->val<<" "<<len<<" "<<len/2<<std::endl;
        if(len == 1){
            return root;
        }else{
            std::vector<int> l_nums(nums.begin(),nums.begin()+len/2);
            // std::cout<<l_nums.size()<<" l_nums"<<len<<std::endl;
            root->left = gan2BST(l_nums);
            std::vector<int> r_nums(nums.begin()+len/2+1, nums.end());
            // std::cout<<r_nums.size()<<" r_nums"<<std::endl;
            root->right = gan2BST(r_nums);
        }
        return root;
    }    
};
