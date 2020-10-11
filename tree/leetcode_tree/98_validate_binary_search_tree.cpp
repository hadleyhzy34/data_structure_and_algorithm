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



class Solution {
public:
    vector<int> inorder;

    void inOrder(TreeNode* root){
        if(!root)return;
        inOrder(root->left);
        inorder.push_back(root->val);
        inOrder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        inOrder(root);
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1])return false;
        }
        return true;
    }
};



class Solution2 {
public:
    bool inOrder(TreeNode* root, int val, int status){
        if(!root)return true;
        if(status==0){
            if(root->val>=val)return false;
        }
        if(status==1){
            if(root->val<=val)return false;
        }
        bool l=inOrder(root->left, val, status);
        bool r=inOrder(root->right, val, status);
        return l&&r;
    }

    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        bool l=inOrder(root->left, root->val, 0);
        bool r=inOrder(root->right, root->val, 1);
        return l&&r&&isValidBST(root->left)&&isValidBST(root->right);
    }
};



