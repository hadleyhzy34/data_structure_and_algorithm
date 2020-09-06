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



class Solution226 {
public:
    int sumOfLeftLeavesFromLeft(TreeNode* root){
        if(!root) return 0;
        if(!root->left&&!root->right)
        return root->val;
        return sumOfLeftLeavesFromLeft(root->left)+sumOfLeftLeavesFromRight(root->right);
    }
    int sumOfLeftLeavesFromRight(TreeNode* root){
        if(!root) return 0;
        return sumOfLeftLeavesFromLeft(root->left)+sumOfLeftLeavesFromRight(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return sumOfLeftLeavesFromLeft(root->left)+sumOfLeftLeavesFromRight(root->right);
    }
};


