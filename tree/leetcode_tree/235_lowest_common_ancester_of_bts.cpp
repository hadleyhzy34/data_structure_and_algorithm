//
//  235_lowest_common_ancester_of_bts.cpp
//  leetcode_tree
//
//  Created by Hadley on 23.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
using namespace std;


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
//    
//    TreeNode* lca(TreeNode* root, TreeNode* p,TreeNode* q){
//        if((root==p||root==q)&&(root->left==p||root->left==q||root->right==q||root->right==p)){
//            return root;
//        }else if((root->left==p||root->left==q)&&(root->right==q||root->right==p)){
//            return 
//        }
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        TreeNode* lca=root;
//        
//    }
//};
