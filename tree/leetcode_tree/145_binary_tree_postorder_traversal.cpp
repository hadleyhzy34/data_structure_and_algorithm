//
//  145_binary_tree_postorder_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 07.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int>res;
        stack<TreeNode*>s;
        s.push(root);
        
        while(!s.empty()){
            int size=int(s.size());
            while(size){
                TreeNode* node=s.top();
                res.push_back(node->val);
                s.pop();
                
                if(node->left){
                    s.push(node->left);
                }
                
                if(node->right){
                    s.push(node->right);
                }
                size--;
            }
        }
        return res;
    }
};


