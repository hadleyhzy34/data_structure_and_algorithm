//
//  623_add_one_row_to_tree.cpp
//  leetcode_tree
//
//  Created by Hadley on 13.07.20.
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
    void addRow(TreeNode* root, int v, int d, int depth){
        if(!root)return;
        if((depth+1)==d){
            if(root->left){
                TreeNode* temp=root->left;
                root->left= new TreeNode(v);
                root->left->left=temp;
            }
            if(root->right){
                TreeNode* temp=root->right;
                root->right= new TreeNode(v);
                root->right->right=temp;
            }
        }else{
            addRow(root->left, v,d,depth+1);
            addRow(root->right, v, d, depth+1);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* temp=root;
            root= new TreeNode(v);
            root->left=temp;
        }else{
           addRow(root, v, d, 1);
        }
        return root;
    }
};




