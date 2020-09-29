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
int solution(int n) {
    int d[31];
    int l = 0;
    while (n > 0) {
        d[l] = n % 2;
        n /= 2;
        l++;
    }
    for(int i=0;i<=4;i++){
        cout<<d[i]<<" ";
    }
    for (int p = 1; p <= l/2; ++p) {
        bool ok = true;
        for (int i = 0; i < l - p; ++i) {
            if (d[i] != d[i + p]) {
                ok = false;
                break;
            }
        }
        cout<<p<<" "<<ok<<endl;
        if (ok) {
            return p;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int n=21;
    cout<<solution(21);
    
    return 0;
}
