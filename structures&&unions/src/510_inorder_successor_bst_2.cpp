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
    Node* inorderSuccessor(Node* node) {
        Node* curSuccessor = nullptr;
        if(node->right){
            curSuccessor = node->right;
            node = node->right;
            while(node->left){
                curSuccessor = node->left;
                node = node->left;
            }
        }else{
            if(node->parent){
                while(node->parent&&node->parent->right==node){
                    node = node->parent;
                }
                if(node->parent&&node->parent->left==node){
                    curSuccessor = node->parent;
                }
            }
        }
        return curSuccessor;
    }
};
