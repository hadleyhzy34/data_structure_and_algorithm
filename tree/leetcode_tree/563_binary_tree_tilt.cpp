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

class Solution1 {
public:
    int maxD=0;
    int maxDiameter(TreeNode* root){
        if(!root)return 0;
        if(!root->left&&!root->right) return 0;
        return max(maxDiameter(root->left),maxDiameter(root->right))+1;
    }
    void maxTree(TreeNode* root){
        if(!root)return;
        int l=0;
        if(root->left) l++;
        if(root->right) l++;
        l+=maxDiameter(root->left)+maxDiameter(root->right);
        if(l>maxD)maxD=l;
        maxTree(root->left);
        maxTree(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        maxTree(root);
        return maxD;
    }
};

class Solution3 {
public:
    int res=0;
    int depth(TreeNode* node){
        if(!node)return 0;
        int l=depth(node->left);
        int r=depth(node->right);
        res+=abs(l-r);
        return l+r+node->val;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        depth(root);
        return res;
    }
};

class Solution4 {
public:
    int sum(TreeNode* node){
        if(!node)return 0;
        int l=sum(node->left);
        int r=sum(node->right);

        return l+r+node->val;
    }
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        return abs(sum(root->left)-sum(root->right))+findTilt(root->left)+findTilt(root->right);
    }
};






