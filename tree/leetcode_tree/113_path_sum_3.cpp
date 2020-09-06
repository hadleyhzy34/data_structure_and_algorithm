//
//  113_path_sum_3.cpp
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

//better solution//
//*https://leetcode.com/problems/path-sum-ii/discuss/723689/C%2B%2B-96-Faster-Easytounderstand-With-Explanation*//


class Solution {
public:
    vector<vector<int>> path(TreeNode* root){
        if(!root)return{};
        if(!root->left&&!root->right)
            return {{root->val}};
        
        vector<vector<int>> a=path(root->left);
        for(auto &x:a)
            x.push_back(root->val);
        vector<vector<int>> b=path(root->right);
        for(auto &x:b)
            x.push_back(root->val);
        a.insert(a.end(), b.begin(),b.end());
        return a;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        for(auto &x:path(root)){
            int s=0;
            for(auto &y:x){
                s+=y;
            }
            if(s==sum){
                reverse(x.begin(), x.end());
                res.push_back(x);
            }
        }
        return res;
    }
};


