//
//  314_binary_tree_vertical_order_traversal.cpp
//  leetcode_dfs
//
//  Created by Hadley on 26.08.20.
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
    void orderVertical(TreeNode* root, vector<vector<int>>&res, int index){
        if(!root)return;
        if(index==-1){
            cout<<index<<" "<<root->val<<endl;
            res.insert(res.begin(),{root->val});
            index=0;
        }else if(index==res.size()){
            cout<<index<<" "<<root->val<<endl;
            res.push_back({root->val});
            index=res.size()-1;
        }else{
            cout<<index<<" "<<root->val<<endl;
            res[index].push_back(root->val);
        }
        
        if(root->left){
            orderVertical(root->left, res, index-1);
        }
        
        if(root->right){
            int temp;
            for(int i=0;i<res.size();i++){
                if(find(res[i].begin(),res[i].end(),root->val)!=res[i].end()){
                    temp=i;
                }
                // for(auto y:x){
                //     cout<<y<<" ";
                // }
                // cout<<endl;
            }
            // cout<<"temp is: "<<temp<<" "<<"root value is: "<<root->val<<endl;
            orderVertical(root->right, res, temp+1);
        }
        
        
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
//        vector<vector<int>>res={{}};
        vector<vector<int>>res={{}};
        orderVertical(root, res, 0);
        return res;
    }
};

class Solution2 {
public:
    void orderVertical(TreeNode* root, int h, int v){
        // if(!root)return;
        m[make_pair(h, v)].push_back(root->val);
        if(root->val==81)cout<<h<<" "<<v<<endl;
        max_v=max(max_v,v);
        min_h=min(min_h,h);
        max_h=max(max_h,h);
        
        if(root->left){
            orderVertical(root->left, h-1, v+1);
        }
        
        if(root->right){
            orderVertical(root->right, h+1, v+1);
        }
        
        
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root)return {};
        orderVertical(root, 0, 0);
        vector<vector<int>>res(max_h-min_h+1);
        for(int i=min_h;i<=max_h;i++){
            for(int j=0;j<=max_v;j++){
                if(i==-1&&j==11)cout<<m[make_pair(i,j)].size()<<" "<<m[make_pair(i,j)][0]<<" "<<m[make_pair(i,j)][1]<<endl;
                if(m.find(make_pair(i, j))!=m.end()){
                    for(auto x:m[make_pair(i,j)]){
                        res[i-min_h].push_back(x);
                    }
//                    if(m[make_pair(i, j)].size()==1){
//                        // cout<<m[make_pair(i,j)][0]<<endl;
//                        res[i-min_h].push_back(m[make_pair(i,j)][0]);
//                    }
//                    else{
//                        res[i-min_h].push_back(m[make_pair(i,j)][0]);
//                        res[i-min_h].push_back(m[make_pair(i,j)][1]);
//                    }
                }
            }
        }
        return res;
    }
private:
    map<pair<int,int>,vector<int>>m;
    int max_v=0;
    int min_h=INT_MAX;
    int max_h=0;
};
