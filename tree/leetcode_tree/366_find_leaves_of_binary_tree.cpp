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
	int dfs(vector<vector<int>>&res,TreeNode* root){
		if(!root)return -1;
		int left=dfs(res,root->left);
		int right=dfs(res,root->right);
		int height=max(left,right)+1;
        // cout<<root->val<<" "<<height<<endl;
        //be careful that res size needs to be expanded
        if(res.size()<=height){
            res.resize(height+1);
        }
		res[height].push_back(root->val);
		return height;
	}

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>>res;
        dfs(res,root);
        return res;
    }
};