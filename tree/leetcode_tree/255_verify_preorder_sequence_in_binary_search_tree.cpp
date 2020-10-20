class Solution {
public:
	bool preOrder(vector<int>& preorder, int l, int r, int lower, int upper){
		if(l>r)return true;
		int root=preorder[l];
		if(root<=lower||root>=upper){
            // cout<<root<<" "<<lower<<" "<<upper<<endl;
            return false;
        }
		int rTree=upper_bound(preorder.begin()+l,preorder.begin()+r+1,root)-preorder.begin();
		bool left=preOrder(preorder,l+1,rTree-1,lower,root);
		bool right=preOrder(preorder,rTree,r,root,upper);
		return left&&right;
	}
    bool verifyPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return preOrder(preorder,0,n-1,INT_MIN,INT_MAX);
    }
};