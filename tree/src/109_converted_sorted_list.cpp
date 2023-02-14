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
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> nums;
        while(head!=NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums){
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

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> nums;
        int len = 0;
        ListNode* tmp = head;
        while(tmp!=NULL){
            len++;
            tmp = tmp->next;
        }
        if(head){
            TreeNode* res = new TreeNode;
            sortedArrayToBST(res, head, len);
            // std::cout<<res->left->val<<std::endl;
            return res;
        }else{
            return nullptr;
        }
    }

    ListNode* sortedArrayToBST(TreeNode* root, ListNode* node, int length){
        if(!length){
            return node;
        }
        if(root == NULL){
            root = new TreeNode;
        }
        if(length/2){
            root->left = new TreeNode;
            node = sortedArrayToBST(root->left, node, length/2);
        }
        root->val = node->val;
        // std::cout<<root->val<<" "<<root->left->val<<std::endl;
        node = node->next;
        if(length-length/2-1){
            root->right = new TreeNode;
            node = sortedArrayToBST(root->right, node, length-length/2-1);
        }
        return node;
    }  
};
