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
    vector<TreeNode*> constructTrees(int start, int end){
        vector<TreeNode*> list;
        if(start>end){
            list.push_back(nullptr);
            return list;
        }
        for(int i=start;i<=end;i++){
            vector<struct TreeNode*> left=constructTrees(start, i-1);
            vector<struct TreeNode*> right=constructTrees(i+1, end);
            
            for(int j=0;j<left.size();j++){
                TreeNode* l=left[j];
                for(int k=0;k<right.size();k++){
                    TreeNode* r=right[k];
                    TreeNode* node=new TreeNode(i);
                    node->left=l;
                    node->right=r;
                    list.push_back(node);
                }
            }
        }
        return list;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return {};
        return constructTrees(1, n);
    }
};
