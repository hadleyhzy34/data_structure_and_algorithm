//
//  536_construct_binary_tree_from_string.cpp
//  string
//
//  Created by Hadley on 24.09.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <unordered_map>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s.empty())return nullptr;
        string root,left,right;
        int count=0;
        int val;
        int pos=s.find('(');
        
        if(pos==-1){
            val = stoi(s);
            return new TreeNode(val);
        }else{
            val = stoi(s.substr(0,pos));
        }
        
        TreeNode* node=new TreeNode(val);
        
        for(int i=pos;i<s.size();i++){
            if(s[i]=='(')count++;
            if(s[i]==')')count--;
            if(count==0){
                node->left=str2tree(s.substr(pos+1,i-pos-1));
                if(i<s.size()-1){
                    node->right=str2tree(s.substr(i+2,(int)s.size()-3-i));
                }
                break;
                }
        }
        cout<<left<<" "<<right<<endl;
        return node;
    }
};
