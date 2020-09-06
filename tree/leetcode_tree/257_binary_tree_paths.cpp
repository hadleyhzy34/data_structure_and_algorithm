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


class Solution1 {
public:
    vector<string> tPaths(TreeNode* root){
        if(!root)return {};
        if(!root->left&&!root->right){
            return {to_string(root->val)};
        }
        vector<string> a=tPaths(root->left);
        for(auto &x:a)
            x=to_string(root->val)+"->"+x;
        
        vector<string> b=tPaths(root->right);
        for(auto &x:b)
            x=to_string(root->val)+"->"+x;
        
        a.insert(a.end(),b.begin(),b.end());
        return a;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        return tPaths(root);
    }
};
