//
//  623_add_one_row_to_tree.cpp
//  leetcode_tree
//
//  Created by Hadley on 13.07.20.
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
    int treeSum(TreeNode* root){
        if(!root)return 0;
        if(!root->left&&!root->right)return root->val;
        return treeSum(root->left)+treeSum(root->right)+root->val;
    }
    vector<int> sum;
    void nodeSum(TreeNode* root){
        if(!root) return;
        sum.push_back(treeSum(root));
        nodeSum(root->left);
        nodeSum(root->right);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root)return{};
        nodeSum(root);
        vector<int>res;
        unordered_map<int, int> count;
        int max=0;
        for(auto &x:sum){
            count[x]++;
            if(count[x]>max){
                max=count[x];
                res={x};
            }else if(count[x]==max){
                res.push_back(x);
            }
        }
        return res;
    }
};





