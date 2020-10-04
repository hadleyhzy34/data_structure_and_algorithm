//
//  94_binary_tree_inorder_tree_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 04.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursively
class Solution {
public:
    void inorder(TreeNode* root, vector<int>&res){
        if(!root)return;
        inorder(root, res);
        res.push_back(root->val);
        inorder(root, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        inorder(root, res);
        return res;
    }
};

//iteratively
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>s;
        if(!root)return {};
        s.push(root);
        
        TreeNode* node=root->left;

        while(!s.empty()||node){
            while(node){
                s.push(node);
                node=node->left;
            }
            res.push_back(s.top()->val);
            if(s.top()->right){
                node=s.top()->right;
            }
            s.pop();
        }
        return res;
    }
};
