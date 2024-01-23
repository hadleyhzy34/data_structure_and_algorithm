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
    bool isValidBST(TreeNode* root) {
        std::vector<int> nums;
        inorder(root, nums);
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>=nums[i]){
                return false;
            }
        }
        return true;
    }

    void inorder(TreeNode* node, std::vector<int>& nums){
        if(node==NULL){
            return;
        }
        inorder(node->left, nums);
        nums.push_back(node->val);
        inorder(node->right, nums);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool check = true;
        inorder(root, &check);
        return check;
    }

    std::pair<int,int> inorder(TreeNode* node, bool *check){
        int l_min, l_max;
        if(node->left){
            std::tie(l_min,l_max) = inorder(node->left, check);
            // std::cout<<"if "<<l_max<<" "<<l_min<<" "<<node->left->val<<std::endl;
            if(l_max >= node->val){
                // std::cout<<"l: "<<l_max<<" "<<node->val<<std::endl;
                *check = false;
            }
        }else{
            l_min = node->val;
            // l_max = node->val;
        }

        int r_min, r_max;
        if(node->right){
            std::tie(r_min,r_max) = inorder(node->right, check);
            if(r_min <= node->val){
                // std::cout<<"r: "<<r_min<<" "<<node->val<<std::endl;
                *check = false;
            }
        }else{
            // r_min = node->val;
            r_max = node->val;
        }

        // std::cout<<"check "<<node->val<<" "<<l_min<<" "<<r_max<<std::endl;
        return std::make_pair(l_min, r_max);
    }
};
