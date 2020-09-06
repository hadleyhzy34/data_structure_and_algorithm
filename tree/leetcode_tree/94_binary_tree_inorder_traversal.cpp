#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution1 {
public:
    vector<int> res;
    void inorder(TreeNode *root){
        if(!root)return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> t;
        if(!root) return {};
        t.push(root);
        
        TreeNode* node=t.top()->left;
        
        while(!t.empty()){
            while(node){
                t.push(node);
                node=node->left;
            }
            
            node=t.top();
            t.pop();
            res.push_back(node->val);
            
            node=node->right;
            if(node){
                t.push(node);
                node=node->left;}
        }
    return res;
    }
};

class Solution3 {
public:
    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> t;
            if(!root) return {};
            t.push(root);
            
            TreeNode* node=root->left;
            
            while(!t.empty()||node){
                while(node){
                    t.push(node);
                    node=node->left;
                }
                
                res.push_back(t.top()->val);
                
                if(t.top()->right)
                    node=t.top()->right;
                t.pop();
            }
        return res;
        }
    };
};



