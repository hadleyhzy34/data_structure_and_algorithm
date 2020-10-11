//
//  429_nary_tree_level_order_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 11.07.20.
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

class Solution {
public:
    TreeNode* treeBuild(vector<int>& inorder, vector<int>& preorder, int l, int r){
        if(l>r)return nullptr;
        TreeNode* t=new TreeNode(preorder[index]);
        int j=find(inorder.begin(),inorder.end(),preorder[index])-inorder.begin();
        // cout<<index<<" "<<t->val<<" "<<j<<endl;
        index++;
        if(l==r)return t;
        t->left=treeBuild(inorder, preorder, l, j-1);
        t->right=treeBuild(inorder, preorder, j+1, r);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return treeBuild(inorder, preorder, 0, preorder.size()-1);
    }
private:
    int index=0;
};









class Solution2 {
public:
    TreeNode* build(vector<int>&preorder,int& index, vector<int>& inorder, int l, int r){
        if(index>=preorder.size()||l>r)return nullptr;
        TreeNode *root = new TreeNode(preorder[index]);
        int j = distance(inorder.begin(), find(inorder.begin() + l, inorder.begin() +r, preorder[index]));
        index++;
        root->left=build(preorder, index, inorder, l, j-1);
        root->right=build(preorder,index, inorder, j+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return build(preorder, index,inorder, 0, inorder.size()-1);
    }
};


class Solution3 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int rootInex = 0;
            return helper(preorder, rootInex, inorder, 0, inorder.size() - 1);
        }
        
    private:
        TreeNode* helper(vector<int>& preorder, int& rootIndex, vector<int>& inorder, int start, int end) {
            if(rootIndex >= preorder.size() || start > end) return nullptr;
            
            TreeNode* root = new TreeNode(preorder[rootIndex]);
            auto pos = distance(inorder.begin(), find(inorder.begin() + start, inorder.begin() + end, preorder[rootIndex]));
            rootIndex ++;
            root->left  = helper(preorder, rootIndex, inorder, start, pos - 1);
            root->right = helper(preorder, rootIndex, inorder, pos + 1, end);
            return root;
        }
};
