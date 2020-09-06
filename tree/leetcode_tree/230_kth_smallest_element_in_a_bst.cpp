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
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    vector<int> st;
    
    void treeSort(TreeNode* root){
        if(!root) return;
        treeSort(root->left);
        st.push_back(root->val);
        treeSort(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        treeSort(root);
        return st[k-1];
    }
};
