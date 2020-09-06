//
//  559_maximum_depth_of_nary_tree.cpp
//  leetcode_tree
//
//  Created by Hadley on 10.07.20.
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



class Solution1 {
public:
    vector<int> res;
    void postOrderPrint(Node* root){
        if(!root)
            return;
        for(auto &x:root->children){
            postOrderPrint(x);
        }
        res.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        postOrderPrint(root);
        return res;
    }
};

class Solution2 {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> t;
        if(!root) return {};
        t.push(root);
            
        while(!t.empty()){
            Node* node=t.top();
            t.pop();
            for(auto x:node->children){
                if(x)
                    t.push(x);
            }
            res.push_back(node->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


