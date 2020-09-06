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

/**
 * Definition for a binary tree node.*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};



class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)return {};
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            auto size=q.size();
            vector<int> r;
            while(size--){
                Node *n=q.front();
                q.pop();
                r.push_back(n->val);
                for(auto &x:n->children){
                    if(x){
                        q.push(x);
                    }
                }
            }
            res.push_back(r);
        }
        return res;
    }
};




