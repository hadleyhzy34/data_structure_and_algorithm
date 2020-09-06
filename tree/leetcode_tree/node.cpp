//
//  node.cpp
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

struct node{
    int data;
    struct node *left;
    struct node *right;
    node():data(0),left(nullptr),right(nullptr){};
    node(int d):data(d),left(nullptr),right(nullptr){};
    node(int d,node *l,node *r):data(d),left(l),right(r){};
};

