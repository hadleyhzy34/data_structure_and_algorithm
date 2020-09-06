//
//  main.cpp
//  leetcode_tree
//
//  Created by Hadley on 23.06.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
//#include "107_binary_tree_level_order.cpp"
//#include "437_path_sum_3.cpp"
//#include "110_balanced_binary_tree.cpp"
#include "199_binary_tree_right_side_view.cpp"
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    node():data(0),left(nullptr),right(nullptr){};
    node(int d):data(d),left(nullptr),right(nullptr){};
    node(int d,node *l,node *r):data(d),left(l),right(r){};
};

//node *newNode(int val){
//    struct node* n= new struct node();
//    n->data = val;
//    n->left = NULL;
//    n->right = NULL;
//    return n;
//}

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode *root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    
    TreeNode *t = new TreeNode(10);
//    Solution437 test1;
//    test1.pathSum(root, 3);
    
//    Solution110 test;
//    test.isBalanced(t);
    
    Solution199 test1;
    test1.rightSideView(root);
    
    return 0;
}
