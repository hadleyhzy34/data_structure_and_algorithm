//
//  101_symmetric_tree.cpp
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


void checkSymmetric(struct TreeNode* node,vector<int>T)
{
    if (node == NULL){
        return;
    }
    // first recur on left subtree
    checkSymmetric(node->left,T);
    
    //print or push back the relatively root value
    T.push_back(node->val);
    // then recur on right subtree
    checkSymmetric(node->right,T);
    // now deal with the node
}

void checkleft(struct TreeNode* node,vector<int>T,vector<int>N)
{
    if (node == NULL){
        T.push_back(0);
        N.push_back(-1);
        return;
    }
    if(node->left==NULL&&node->right==NULL){
        T.push_back(node->val);
        N.push_back(0);
        return;
    }
    // first recur on left subtree
    checkSymmetric(node->left,T);
    
    //print or push back the relatively root value
    T.push_back(node->val);
    // then recur on right subtree
    checkSymmetric(node->right,T);
    // now deal with the node
}

void checkright(struct TreeNode* node,vector<int>T,vector<int>N)
{
    if (node == NULL){
        T.push_back(0);
        N.push_back(-1);
        return;
    }
    if(node->left==NULL&&node->right==NULL){
        T.push_back(node->val);
        N.push_back(0);
        return;
    }
    // first recur on left subtree
    checkSymmetric(node->right,T);
    
    //print or push back the relatively root value
    T.push_back(node->val);
    // then recur on right subtree
    checkSymmetric(node->left,T);
    // now deal with the node
}

bool mirror(TreeNode* lr, TreeNode* rr){
    if(!lr&&!rr)return true;
    if(!lr||!rr)return false;
    return lr->val==rr->val
    &&mirror(lr->left, rr->right)
    &&mirror(lr->right, rr->left);
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return mirror(root->left,root->right);
    }
};
