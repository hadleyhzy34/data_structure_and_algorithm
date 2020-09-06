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
