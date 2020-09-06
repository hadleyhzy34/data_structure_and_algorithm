//
//  116_populating_next_right_pointers_in_each_node.cpp
//  leetcode_tree
//
//  Created by Hadley on 13.07.20.
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


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            auto size=q.size();
            while(size--){
                Node *node=q.front();
                q.pop();
                
                if(node->left){
                    node->left->next=node->right;
                    q.push(node->left);
                }
                if(node->right){
                    if(node->next){
                        node->right->next=node->next->left;
                    }
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};

class Solution2 {
public:
    void populate(Node* left, Node* right){
        if(!left&&!right)return;
        left->next=right;
        populate(left->left,left->right);
        populate(right->left, right->right);
        populate(left->right, right->left);
    }
    Node* connect(Node* root) {
        if(root==NULL) return nullptr;
        populate(root->left, root->right);
        return root;
    }
};

