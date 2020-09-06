//
//  94_binary_tree_inorder_traversal.cpp
//  LeetCode_stack
//
//  Created by Hadley on 24.04.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        TreeNode* test=root;
//        while(test->left->left){
//            test=test->left;
//        }
//        stack<TreeNode*>s;
//        s.push(<#const value_type &__v#>)
//    }
//};
