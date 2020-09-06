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


class Solution {
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

