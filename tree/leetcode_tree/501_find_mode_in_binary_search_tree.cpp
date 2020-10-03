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


//better solution:https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/705340/C%2B%2B-greater-Beats-90.9-solutions(In-order-Traversal)-Easy-to-understand

class Solution {
public:
    vector<int> find(TreeNode* root){
        if(!root)return {};
        if(!root->left&&!root->right)
            return {root->val};
        vector<int> a=find(root->left);
        vector<int> b=find(root->right);
        a.insert(a.end(), b.begin(),b.end());
        a.push_back(root->val);
        return a;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        vector<int> r=find(root);
        
        int maxCount=0;
        unordered_map<int, int> count;
        for(auto it=r.begin();it!=r.end();it++){
            count[*it]++;
        }
        for(auto x:count){
            if(maxCount<x.second){
                res={x.first};
                maxCount=x.second;
            }else if(maxCount==x.second){
                res.push_back(x.first);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> res;
    int maxFre=0,curFre=0,pre=INT_MIN;
    void dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);
        if(pre==root->val){
            curFre++;
        }else{
            curFre=1;
            pre=curFre;
        }
        if(curFre>maxFre){
            res.clear();
            maxFre=curFre;
            res.push_back(root->val);
        }else if(curFre==maxFre){
            res.push_back(root->val);
        }
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};



