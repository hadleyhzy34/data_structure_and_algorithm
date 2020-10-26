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
class Solution {
public:
    //return consecutive path length starting from current node root
    int longestC(TreeNode* root, int &max_length){
		if(!root)return 0;
		int length=1;
        int left=longestC(root->left,max_length);
        if(root->left&&root->left->val-root->val==1){
            length=max(length,left+1);
        }
		
        int right=longestC(root->right,max_length);
        if(root->right&&root->right->val-root->val==1){
            length=max(length,right+1);
        }
        max_length=max(max_length,length);
        return length;
	}

    int longestConsecutive(TreeNode* root) {
        int max_length=0;
        longestC(root,max_length);
        return max_length;
    }
};