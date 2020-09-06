//
//  105_construct_binary_tree_from_preorder_and_inorder_traversal.cpp
//  leetcode_dfs
//
//  Created by Hadley on 25.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
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
#include <map>
#include <filesystem>
#include <dirent.h>
using namespace std;


//Definition for a binary tree node.
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
