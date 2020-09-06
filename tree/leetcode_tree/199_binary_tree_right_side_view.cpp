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


class Solution199 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return {};
        
        queue<TreeNode *>q;
        q.push(root);
                
        while(!q.empty())
        {
            res.push_back(q.back()->val);
            auto size=q.size();
            while(size--)
            {
                TreeNode *node=q.front();
                q.pop();
                
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
        }
        return res;
    }
};


