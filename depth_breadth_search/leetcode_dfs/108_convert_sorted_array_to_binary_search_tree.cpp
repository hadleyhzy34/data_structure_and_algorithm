//
//  108_convert_sorted_array_to_binary_search_tree.cpp
//  leetcode_dfs
//
//  Created by Hadley on 26.08.20.
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
    TreeNode* tobst(vector<int>& inorder, int l, int r){
        if(l>r)return nullptr;
        auto n=(r-l+1)/2+l;
        TreeNode* t=new TreeNode(inorder[n]);
        if(l==r)return t;
        t->left=tobst(inorder,l,n-1);
        t->right=tobst(inorder,n+1,r);
        return t;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return tobst(nums, 0, nums.size()-1);
    }
};
