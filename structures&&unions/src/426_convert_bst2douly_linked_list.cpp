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
    Node* treeToDoublyList(Node* root) {
        if(!root){
            return root;
        }
        std::vector<Node*> res;     
        sortedArrayToBST(root, res);
        // std::cout<<"size: "<<res.size()<<std::endl;
        int size = res.size();
        for(int i=0;i<size;i++){
            // std::cout<<"check: "<<i<<" "<<res[i]->val<<std::endl;
            if(i==0){
                res[0]->right = res[(i+1)%size];
                res[0]->left = res[size-1];
            }else if(i==size-1){
                res[i]->right = res[0];
                res[i]->left = res[i-1];
            }else{
                res[i]->left = res[i-1];
                res[i]->right = res[i+1];
            }
            // std::cout<<res[i]->val<<std::endl;
        }
        return res[0];
    }

    void sortedArrayToBST(Node* node, std::vector<Node*> &res){
        if(!node){
            return;
        }
        sortedArrayToBST(node->left, res);
        res.push_back(node);
        sortedArrayToBST(node->right, res);
    }
};
