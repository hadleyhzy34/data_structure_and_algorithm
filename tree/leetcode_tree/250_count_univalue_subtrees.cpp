//
//  100_same_tree.cpp
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

class Solution {
public:
    bool checkUnival(TreeNode* node, int val){
        if(!node)return true;
        if(node->val!=val){
          return false;
        }
        bool l=checkUnival(node->left,val);
        bool r=checkUnival(node->right,val);
        return l&&r;
    }

    int countUnivalSubtrees(TreeNode* root) {
        if(!root)return 0;
        if(checkUnival(root,root->val)){
          return 1+countUnivalSubtrees(root->left)+countUnivalSubtrees(root->right);
        }else{
          return countUnivalSubtrees(root->left)+countUnivalSubtrees(root->right);
        }
    }
};


class Solution2 {
public:
    bool checkUnival(TreeNode* node, int val){
        if(!node)return true;
        if(node->val!=val){
          return false;
        }
        bool l=checkUnival(node->left,val);
        bool r=checkUnival(node->right,val);
        return l&&r;
    }

    int countUnivalSubtrees(TreeNode* root) {
        if(!root)return 0;
        if(checkUnival(root,root->val)){
          return 1+countUnivalSubtrees(root->left)+countUnivalSubtrees(root->right);
        }else{
          return countUnivalSubtrees(root->left)+countUnivalSubtrees(root->right);
        }
    }
};
