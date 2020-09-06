//
//  107_binary_tree_level_order_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 23.06.20.
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


//class Solution {
//public:
//    void arrayToBst(TreeNode* root){
//        
//        arrayToBst(root->left);
//        arrayToBst(root->right);
//    }
//    
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        TreeNode* res;
//        if(nums.empty())
//            return {};
//        /*depth of the bst*/
//        int depth=1;
//        while(pow(2,depth)-1<nums.size()){
//            depth++;
//        }
//        
//        
//    }
//};
