//
//  100_same_tree.cpp
//  leetcode_tree
//
//  Created by Hadley on 23.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
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

//be very carefull that boolean needs to be passed by reference                       
void printPostorder(struct TreeNode* node1, struct TreeNode* node2, bool &pass)
{
    if (node1 == NULL&&node2==NULL){
        return;
    }else if(node1==NULL || node2==NULL){
        pass=false;
        return;
    }
    cout<<node1->val<<" "<<node2->val<<endl;
    // first recur on left subtree
    printPostorder(node1->left,node2->left,pass);
  
    // then recur on right subtree
    printPostorder(node1->right,node2->right,pass);
    cout<<pass<<" "<<endl;
    // now deal with the node
    // cout<<node->val<<endl;
    if(node1->val!=node2->val){
        pass=false;
    }
    cout<<pass<<" "<<endl;
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool test=true;
        printPostorder(p, q,test);
        return test;
    }
};
