//
//  366_find_leaves_of_bianry_tree.cpp
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
    int dfs(TreeNode* root){
        if(!root)return 0;
        int l=dfs(root->left)+1;
        int r=dfs(root->right)+1;
        int index=max(l,r)-1;
        if(index>=res.size())res.push_back({});
        res[index].push_back(root->val);
        return max(l,r);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
private:
    vector<vector<int>>res;
};
