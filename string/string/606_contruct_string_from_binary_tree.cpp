//
//  606_contruct_string_from_binary_tree.cpp
//  string
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
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
    string tree2str(TreeNode* t) {
        if(!t)return "";
        string res;
        res+=to_string(t->val);
        if(!t->left&&!t->right)return res;
        res=res+"("+tree2str(t->left)+")";

        if(t->right){
            res=res+"("+tree2str(t->right)+")";
        }
        return res;
    }
};
