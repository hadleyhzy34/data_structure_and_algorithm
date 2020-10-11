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
    vector<string> p;
    void path(TreeNode* root, string s){
        if(!root){
            return;
        }
        if(!root->left&&!root->right){
            p.push_back(s);
            return;
        }
        if(root->left)
            path(root->left, s+to_string(root->left->val));
        if(root->right)
            path(root->right, s+to_string(root->right->val));
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        path(root, to_string(root->val));
        int sum=0;
        for(auto &x:p){
            sum+=std::stoi(x);
        }
        return sum;
    }
};

class Solution2 {
public:
    vector<int> p;
    void path(TreeNode* root, int sum){
        if(!root){
            return;
        }
        if(!root->left&&!root->right){
            p.push_back(10*sum+root->val);
            return;
        }
        if(root->left)
            path(root->left, 10*sum+root->val);
        if(root->right)
            path(root->right, 10*sum+root->val);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        path(root, 0);
        return accumulate(p.begin(), p.end(), 0);
    }
};

