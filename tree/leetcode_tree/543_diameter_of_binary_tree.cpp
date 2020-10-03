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

class solution{
public:
    int res=0;
    int depth(TreeNode* root){
        if(!root)return 0;
        int l=depth(root->left);
        int r=depth(root->right);
        res=max(res,l+r);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        depth(root);
        return res;
    }
};

class solution3{
public:
    int depth(TreeNode* root){
        if(!root)return 0;
        if(!root->left&&!root->right)return 0;
        int l=depth(root->left);
        int r=depth(root->right);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int l=root->left?depth(root->left)+1:0;
        int r=root->right?depth(root->right)+1:0;
        int tilt=l+r;
        return max(tilt, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};

class solution4{
public:
    int depth(TreeNode* root){
        if(!root)return 0;
        int l=depth(root->left);
        int r=depth(root->right);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        return max(depth(root->left)+depth(root->right),max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};
