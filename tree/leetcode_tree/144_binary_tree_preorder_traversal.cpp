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
    void preorder(TreeNode *root){
        if(!root)return;
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
};

class Solution2 {
public:
    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> t;
            if(!root) return {};
            t.push(root);
            
            
            while(!t.empty()){
                TreeNode* node=t.top();
                t.pop();
                
                res.push_back(node->val);
                if(node->right)
                    t.push(node->right);
                if(node->left)
                    t.push(node->left);
            }
        return res;
        }
    };
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
            
            
            while(!t.empty()){
                res.push_back(t.top()->val);
                TreeNode* node=t.top();
                t.pop();
                
                if(node->right){
                    t.push(node->right);
                }
                if(node->left){
                    t.push(node->left);
                }
            }
        return res;
        }
    };
};




