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


class Solution110 {
public:
    int height(TreeNode* root){
        if(!root)return 0;
        if(!root->left)
            return height(root->right)+1;
        if(!root->right)
            return height(root->left)+1;
        return max(height(root->left),height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            if(abs(height(node->left)-height(node->right))>1)
                return false;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return true;
    }
};

