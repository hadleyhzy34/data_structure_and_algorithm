//
//  107_binary_tree_level_order_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 23.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

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



class Solution437 {
public:
    int path=0;
    void checkSum(TreeNode* root, int sum){
        if(!root) return;
        if(!root->left&&!root->right){
            if(sum-root->val==0){
                path++;}
            return;}
        if(sum==root->val) {
            path++;}
        
        checkSum(root->left, sum-root->val);
        checkSum(root->right, sum-root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty()==false){
            TreeNode* node= q.front();
            q.pop();
            checkSum(node, sum);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return path;
    }
};


class Solution437_2 {
public:
    int path=0;
    void checkSum(TreeNode* root, int sum){
        if(!root) return;
        if(!root->left&&!root->right){
            if(sum-root->val==0){
                path++;
                cout<<root->val<<" "<<path<<endl;}
            return;}
        if(sum==root->val) {
            path++;
        cout<<root->val<<" "<<path<<endl;}
        
        checkSum(root->left, sum-root->val);
        checkSum(root->right, sum-root->val);
    }
    
    void check(TreeNode* root, int sum){
        if(!root) return;
        checkSum(root, sum);
        check(root->left, sum);
        check(root->right, sum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        check(root,sum);
        return path;
    }
};


