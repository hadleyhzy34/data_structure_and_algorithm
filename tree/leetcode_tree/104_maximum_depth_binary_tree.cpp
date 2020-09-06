//
//  104_maximum_depth_binary_tree.cpp
//  leetcode_tree
//
//  Created by Hadley on 23.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
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
    int maxDepth(TreeNode* root) {
        if(!root){
        return 0;
    }else{
        int ldepth=maxDepth(root->left);
        int rdepth=maxDepth(root->right);
        
        /* use the larger one, if both child nodes are null, then just add one more*/
        if (ldepth > rdepth)
            return(ldepth + 1);
        else return(rdepth + 1);
    }
    }
};
