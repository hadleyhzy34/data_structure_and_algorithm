//
//  106_construct_binary_tree_from_inorder_and_postorder.cpp
//  leetcode_tree
//
//  Created by Hadley on 08.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Solution {
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    }
};
