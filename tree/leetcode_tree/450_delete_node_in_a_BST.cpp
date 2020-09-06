//
//  429_nary_tree_level_order_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 11.07.20.
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


class Solution450 {
public:
    TreeNode* searchSmallestNode(TreeNode* root) {
        if(!root)return nullptr;
        while(root->left){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val<key) root->right= deleteNode(root->right, key);
        if(root->val>key) root->left= deleteNode(root->left, key);
        if(root->val==key){
            if(root->left&&root->right){
                TreeNode* temp=searchSmallestNode(root->right);
                root->val=temp->val;
                root->right=deleteNode(root->right, temp->val);
            }else if(!root->left){
                return root->right;
            }else{
                return root->left;
            }
        }
        return root;
    }
};



