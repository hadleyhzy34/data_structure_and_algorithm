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
        vector<vector<Node*>> res;
        if(root==NULL) return {};
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<Node*> v;
            auto size=q.size();
            while(size--){
                Node *node=q.front();
                q.pop();
                v.push_back(node);
                
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(v);
        }
        for(auto &x:res){
            vector<Node*> r=x;
            for(int i=0;i<r.size()-1;i++){
                r[i]->next=r[i+1];
            }
        }
        return root;
    }
};





class Solution2 {
public:
    Node* connect(Node* root) {
        if(root==NULL) return {};
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<Node*>subset;
            int size=q.size();
            while(size--){
                Node* temp=q.front();
                q.pop();
                subset.push_back(temp);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            for(int i=0;i<subset.size()-1;i++){
                subset[i]->next=subset[i+1];
            }
        }
        return root;
    }
};










































