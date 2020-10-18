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
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if(!root)return;
        stack<TreeNode*> s;
        s.push(root);

        TreeNode *node=s.top()->left;
        while(!s.empty()||node){

            while(node){
                s.push(node);
                node=node->left;
            }
            q.push(s.top()->val);

            if(s.top()->right){
                node=s.top->right;
            }
            s.pop();
        }
    }
private:
    queue<int> q;
};




