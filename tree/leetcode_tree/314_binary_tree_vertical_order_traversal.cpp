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

//bfs
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
       if(!root)return {};
       //int->col, vector<int>->node value
        std::map<int, vector<int>> map; 
       queue<pair<TreeNode*,int>> q;
       q.push(make_pair(root,0));


       while(!q.empty()){
       	    int size=q.size();
       	    while(size--){
       	    	TreeNode* temp=q.front().first;
       	    	int col=q.front().second;
       	    	map[col].push_back(temp->val);
       	    	q.pop();
                if(temp->left){
       	    		q.push(make_pair(temp->left,col-1));
       	    	}
       	    	if(temp->right){
       	    		q.push(make_pair(temp->right,col+1));
       	    	}
                // cout<<size<<" "<<temp->val<<endl;
       	    }
       }

       vector<vector<int>>res;
       for(auto x:map){
       	res.push_back(x.second);
       }
       return res;
    }
};


//dfs
class Solution2 {
public:
    void orderVertical(TreeNode* root, int h, int v){
        m[make_pair(h, v)].push_back(root->val);
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
                if(m.find(make_pair(i, j))!=m.end()){
                    for(auto x:m[make_pair(i,j)]){
                        res[i-min_h].push_back(x);
                    }
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