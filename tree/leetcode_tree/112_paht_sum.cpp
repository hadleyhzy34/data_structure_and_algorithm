//
//  112_paht_sum.cpp
//  leetcode_tree
//
//  Created by Hadley on 25.09.20.
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
    bool checkSum(TreeNode* root,int sum){
        if(!root)return false;
        if(!root->left&&!root->right){
            return sum==root->val;
        }

        return checkSum(root->left, sum-root->val)||checkSum(root->right, sum-root->val);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        // if(!root->left){
        //     return checkSum(root->right,sum-root->val);
        // }else if(!root->right){
        //     return checkSum(root->left,sum-root->val);
        // }
        return checkSum(root, sum);
    }
};
