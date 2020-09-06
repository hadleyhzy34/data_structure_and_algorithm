//
//  107_binary_tree_level_order_traversal.cpp
//  leetcode_tree
//
//  Created by Hadley on 23.06.20.
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

//void printLevelOrder(TreeNode *root){
//    if(root==NULL) return;
//
//            queue<TreeNode *> q;
//            vector<int>d;
//
//    int depth=0;
//            q.push(root);
//    d.push_back(depth);
//
//            while(q.empty()==false){
//    //            res.push_back(q.front());
//
//                if(q.front()->left!=NULL)
//                    q.push(root->left);
//                    d.push_back(d.front()+1);
//                if(q.front()->right!=NULL)
//                    q.push(root->right);
//                    d.push_back(d.front()+1);
//                q.pop();
//            }
//}

//BFS solution https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/699659/C%2B%2B-Easiest-BFS.DFS-explained-solution-4ms-beats-91
class Solution107 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return {};
        
        queue<TreeNode *>q;
        q.push(root);
                
        while(!q.empty())
        {
            vector<int> v;
            auto size=q.size();
            while(size--)
            {
                TreeNode *node=q.front();
                q.pop();
                v.push_back(node->val);
                
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            res.push_back(v);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

