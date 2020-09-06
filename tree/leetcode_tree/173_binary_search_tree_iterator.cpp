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
        stack<TreeNode*> t;
        if(!root)return;
        t.push(root);
        
        TreeNode* node=root->left;
        
        while(!t.empty()||node){
            while(node){
                t.push(node);
                node=node->left;
            }
            
            S.push(t.top()->val);
            
            if(t.top()->right)
                node=t.top()->right;
            t.pop();
        }
        
    }
    
    /** @return the next smallest number */
    int next() {
        int n=S.front();
        S.pop();
        return n;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }
private:
    queue<int> S;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */




