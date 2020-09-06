//
//  133_clone_graph.cpp
//  leetcode_dfs
//
//  Created by Hadley on 27.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <iostream>
#include <fstream>
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
#include <map>
#include <filesystem>
#include <dirent.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void graphClone(Node* node, Node* clone){
        clone->val=node->val;
        if(clonelist.size()<=clone->val){
            clonelist.resize(clone->val+1);
            clonelist[clone->val]=clone;
        }else{
            clonelist[clone->val]=clone;
        }
        for(auto x:node->neighbors){
            if(x->val>=clonelist.size()||clonelist[x->val]==nullptr){
                Node* adj=new Node(x->val);
                clone->neighbors.push_back(adj);
                graphClone(x, adj);
            }else{
                clone->neighbors.push_back(clonelist[x->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        vector<Node*>clonelist;
        Node* clone = new Node();
        graphClone(node, clone);
        return clone;
    }
private:
    vector<Node*>clonelist;
};
