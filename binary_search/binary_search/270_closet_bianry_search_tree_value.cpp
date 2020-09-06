//
//  270_closet_bianry_search_tree_value.cpp
//  binary_search
//
//  Created by Hadley on 05.08.20.
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
    vector<int> orderTree;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        orderTree.push_back(root->val);
        inorder(root->right);
    }
    int closestValue(TreeNode* root, double target) {
        if(!root)return 0;
        inorder(root);
        auto n=orderTree.size();
        int l=0, r=n;
        if(target<orderTree[0])return orderTree[0];
        if(target>orderTree[n-1])return orderTree[n-1];
        while(l<=n){
            int mid=l+(r-l)/2;
            if(orderTree[mid]<=target){
                if(orderTree[mid+1]>target){
                    return (target-orderTree[mid])>(orderTree[mid+1]-target)?orderTree[mid+1]:orderTree[mid];
                }else{
                    l=mid+1;
                }
            }else{
                r=mid-1;
            }
        }
        return 0;
    }
};
