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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return {};
        
        bool flip=true;
        queue<TreeNode *>q;
        q.push(root);
                
        while(!q.empty())
        {
            vector<int> v;
            auto size=q.size();
            while(size--)
            {
                TreeNode *node=q.front();
                q.pop();
                v.push_back(node->val);
                
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            if(flip){
                res.push_back(v);
                flip=false;
            }else{
                reverse(v.begin(), v.end());
                res.push_back(v);
                flip=true;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> s;
        s.push(root);
        
        vector<vector<int>>res;
        bool flip=false;
        
        while(!s.empty()){
            int size=int(s.size());
            vector<int>t;
            while(size--){
                TreeNode *temp=s.front();
                t.push_back(temp->val);
                s.pop();
                if(temp->left){
                    s.push(temp->left);
                }
                if(temp->right){
                     s.push(temp->right);
                }
            }
            if(flip){
                reverse(t.begin(),t.end());
            }
            flip=!flip;
            res.push_back(t);
        }
        return res;
    }
};
