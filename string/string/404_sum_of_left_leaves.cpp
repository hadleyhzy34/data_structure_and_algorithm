//
//  404_sum_of_left_leaves.cpp
//  string
//
//  Created by Hadley on 29.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;


//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    int dfs(TreeNode*node, bool left){
        if(!node)return 0;
        if(left&&!node->left&&!node->right){
            return node->val;
        }
        return dfs(node->left,true)+dfs(node->right,false);
    }
    int sumOfLeavesSum(TreeNode* root){
        if(!root)return 0;
        return dfs(root->left,true)+dfs(root->right,false);
    }
};
