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


//BFS solution https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/699659/C%2B%2B-Easiest-BFS.DFS-explained-solution-4ms-beats-91
class Solution111_1 {
public:
    int minDepth(TreeNode* root) {
        int depth=0;
        if(root==NULL) return depth;
        
        queue<TreeNode *>q;
        q.push(root);
        depth++;
                
        while(!q.empty())
        {
            auto size=q.size();
            while(size--)
            {
                TreeNode *node=q.front();
                q.pop();
                
                if(node->left!=NULL)
                    q.push(node->left);
                
                if(node->right!=NULL)
                    q.push(node->right);
                
                if(node->left==NULL&&node->right==NULL)
                    return depth;
            }
            depth++;
        }
        return depth;
    }
};

class Solution111_2 {
public:
    int minDepth(TreeNode* root) {
        int depth=0;
        if(root==NULL) return depth;
        
        if(!root->left)
            return minDepth(root->right)+1;
        if(!root->right)
            return minDepth(root->left)+1;
        
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};

