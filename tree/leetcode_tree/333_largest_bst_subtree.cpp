/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//find largest BST given BST 
class Solution {
public:
	//return number of nodes of current tree
	int lSubtree(TreeNode* root){
		if(!root)return 0;
		return 1+lSubtree(root->left)+lSubtree(root->right);
	}
    int largestBSTSubtree(TreeNode* root) {
    	if(!root)return 0;
        int left=lSubtree(root->left);
        int right=lSubtree(root->right);
        return max(left,right);
    }
};


//find largest BST given binary tree using BFS traversal
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
    	if(!root)return 0;
    	stack<TreeNode*>s;
        s.push(root);
        int max_length=0;
        int cur_length=0;
        int pre=INT_MIN;

        TreeNode*node=s.top()->left;
        while(!s.empty()||node){
        	while(node){
        		s.push(node);
        		node=node->left;
        	}

        	if(s.top()->val>pre){
        		cur_length++;
        		max_length=max(max_length,cur_length);
        	}else{
        		cur_length=1;
        	}
        	pre=s.top()->val;

        	if(s.top()->right){
        		node=s.top()->right;
        	}
        	s.pop();
        }
        return max_length;
    }
};


//find largest binary search tree given binary tree using BFS traversal
class Solution {
public:
	bool isBST(TreeNode* root, int &res, int &lower, int &upper){
		if(!root)return true;

		int left_size=0,right_size=0;

		int left_lower,left_upper,right_lower,right_upper;


		bool left=isBST(root->left,left_size,left_lower,left_upper);
		bool right=isBST(root->right,right_size,right_lower,right_upper);
		if(left&&right){
			if((!root->left||root->val>left_upper)&&(!root->right||root->val<right_lower)){
				res=left_size+right_size+1;
				lower=root->left?left_lower:root->val;
				upper=root->right?right_upper:root->val;
				return true;
			}
		}
		res=max(left_size,right_size);
		return false;
	}
    int largestBSTSubtree(TreeNode* root) {
    	int res=0,lower=INT_MIN,upper=INT_MAX;
    	isBST(root,res,lower,upper);
    	return res;
    }
};