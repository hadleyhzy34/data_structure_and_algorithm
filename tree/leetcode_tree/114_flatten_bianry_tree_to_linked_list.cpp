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
    vector<TreeNode*>v;
    void seriesNode(TreeNode* root){
        if(!root)return;
        v.push_back(root);
        seriesNode(root->left);
        seriesNode(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        seriesNode(root);
        for(int i=0;i<v.size()-1;i++){
            cout<<v[i]->val<<endl;
            v[i]->left=nullptr;
            v[i]->right=v[i+1];
        }
    }
};


class Solution3 {
public:
    //return tail of current root
    TreeNode* dfs(TreeNode* root){
        if(!root) return nullptr;
        if(!root->left&&!root->right)return root;
        TreeNode* l=dfs(root->left);
        TreeNode* r=dfs(root->right);
        
        if(l){
            l->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }
        return r==nullptr?l:r;
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        dfs(root);
    }
};






