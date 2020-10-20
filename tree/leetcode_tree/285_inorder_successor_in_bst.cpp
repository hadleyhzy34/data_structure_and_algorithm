/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	if(!root)return nullptr;
        stack<TreeNode*> s;
        s.push(root);

        TreeNode* node=root->left;
        bool check=false;
        while(!s.empty()||node){
        	while(node){
        		s.push(node);
        		node=node->left;
        	}

        	if(check){
        		return s.top();
        	}
        	if(s.top()==p){
        		check=true;
        	}
        	if(s.top()->right){
        		node=s.top()->right;
        	}
        	s.pop();
        }
        return nullptr;
    }
};