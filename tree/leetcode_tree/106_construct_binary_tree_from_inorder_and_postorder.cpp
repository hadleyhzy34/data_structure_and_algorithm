//
//  106_construct_binary_tree_from_inorder_and_postorder.cpp
//  leetcode_tree
//
//  Created by Hadley on 08.10.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include "/usr/local/include/bits/stdc++.h"
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

//l and r to track current boundary of subtree from inorder, index indicate index of current root node 
//from postorder
class Solution {
public:
	TreeNode* btree(vector<int>&inorder,vector<int>&postorder,int l,int r, int &index){
		if(l>r)return nullptr;
		TreeNode* root=new TreeNode(postorder[index]);
		int j=find(inorder.begin()+il,inorder.end()+ir,postorder[index])-inorder.begin();
		index--;
		root->right=btree(inorder,postorder,j+1,r,index);
		root->left=btree(inorder,postorder,l,j-1,index);
		return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	int index=postorder.size()-1;
    	return btree(inorder,postorder,0,postorder.size()-1,index);
    }
};

class Solution2 {
public:
	TreeNode* btree(vector<int>&inorder,vector<int>&postorder,int il,int ir, int pl,int pr){
		if(il>ir||pl>pr)return nullptr;
		TreeNode* root=new TreeNode(postorder[pr]);

		int j=find(inorder.begin()+l,inorder.end()+r,postorder[pr])-inorder.begin();
		//number of nodes that are left of current nodes
		int n=j-il;
		
		root->left=btree(inorder,postorder,il,j-1,pl,pl+n-1);
		root->right=btree(inorder,postorder,j+1,ir-1,pl+n,pr-1);

		return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	int index=postorder.size()-1;
    	return btree(inorder,postorder,0,postorder.size()-1,0,postorder.size()-1);
    }
};
