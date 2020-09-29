//
//  235_lowest_common_ancestor_of_a_binary_search_tree.cpp
//  leetcode_tree
//
//  Created by Hadley on 27.09.20.
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
    bool lca(TreeNode* root, TreeNode*p){
        if(!root)return false;
        if(root==p)return true;
        return lca(root->left,p)||lca(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;
        if(root==p||root==q)return root;
    if((lca(root->left,p)&&lca(root->right,q))||(lca(root->right,p)&&lca(root->left,q)))return root;
        if(lca(root->left,p)&&lca(root->left,q))return lowestCommonAncestor(root->left, p, q);
        if(lca(root->right,p)&&lca(root->right,q))return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
