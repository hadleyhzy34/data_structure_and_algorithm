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
    vector<int> pathSum(TreeNode* root){
        if(!root)return{};
        if(!root->left&&!root->right)
            return {root->val};
        
        vector<int> a=pathSum(root->left);
        for(auto &x:a)
            x+=root->val;
        vector<int> b=pathSum(root->right);
        for(auto &x:b)
            x+=root->val;
        a.insert(a.end(), b.begin(),b.end());
        return a;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        vector<int> s=pathSum(root);
        return count(s.begin(),s.end(),sum);
    }
};

class Solution1 {
public:
    bool checkSum(TreeNode* root, int sum){
        if(!root) return false;
        if(!root->left&&!root->right)
            if(sum-root->val==0)
                return true;
            else return false;
        
        bool l=checkSum(root->left, sum-root->val);
        bool r=checkSum(root->right, sum-root->val);
        return l||r;
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return checkSum(root, sum);
    }
};


