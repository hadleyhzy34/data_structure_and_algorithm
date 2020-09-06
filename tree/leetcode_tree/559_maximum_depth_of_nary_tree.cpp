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



class Solution {
public:
    int Depth(Node* root){
        if(!root)
            return 0;
        if(root->children.empty())
            return 1;
        vector<int> d;
        for(auto &x:root->children){
            d.push_back(Depth(x));
        }
        return *std::max_element(d.begin(), d.end())+1;
    }
    
    int maxDepth(Node* root) {
        return Depth(root);
    }
};
