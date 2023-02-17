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
    TreeNode* inorderSuccessor1(TreeNode* root, TreeNode* p) {
        std::vector<TreeNode*> res;
        inorderCheck(root, res);
        for(int i=0;i<res.size();i++){
            if(res[i]==p){
                if(i<res.size()-1){
                    return res[i+1];
                }else{
                    return nullptr;
                }
            }
        }
        return nullptr;
    }
    
    void inorderCheck(TreeNode* node, std::vector<TreeNode*>& res){
        if(!node){
            return;
        }
        inorderCheck(node->left, res);
        res.push_back(node);
        inorderCheck(node->right, res);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* curSuccessor = nullptr;
        if(p->right){
            curSuccessor = p->right;
            p = p->right;
            while(p->left){
                curSuccessor = p->left;
                p = p->left;
            }
            return curSuccessor;
        }

        TreeNode* node = root;
        while(node){
            if(node->val <= p->val){
                node = node->right;
            }else{
                curSuccessor = node;
                std::cout<<node->val<<" "<<curSuccessor->val<<std::endl;
                node = node->left;
            }
        }

        return curSuccessor;
    }

    // TreeNode* newCheck(TreeNode* node, TreeNode* p, TreeNode* curSuccessor){
    //     if(!node){
    //         return;
    //     }
    //     if(node->val == p->val){
    //         return curSuccessor;
    //     }elif(node->val < p->val){
    //         return newCheck(node->right, p);
    //     }else{
    //         return newCheck(node->left, p, node);
    //     }
    //     inorderCheck(node->left, res);
    //     res.push_back(node);
    //     inorderCheck(node->right, res);
    // }
};
