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



class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int>res;
        queue<TreeNode *>q;
        q.push(root);
                
        while(!q.empty())
        {
                TreeNode *node=q.front();
                q.pop();
                res.push_back(node->val);
                
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
        }
        std::sort(res.begin(),res.end());
        int getMinimum=abs(res[1]-res[0]);
        for(int i=1;i<res.size();i++){
            if(abs(res[i]-res[i-1])<getMinimum)
                getMinimum=abs(res[i]-res[i-1]);
        }
        return getMinimum;
    }
};
