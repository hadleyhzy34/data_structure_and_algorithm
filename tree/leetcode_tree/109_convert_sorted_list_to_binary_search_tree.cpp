/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* tobst(vector<int>& inorder, int l, int r){
        if(l>r)return nullptr;
        auto n=(r-l+1)/2+l;
        TreeNode* t=new TreeNode(inorder[n]);
        if(l==r)return t;
        t->left=tobst(inorder,l,n-1);
        t->right=tobst(inorder,n+1,r);
        return t;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>res;
        while (head) {
            res.push_back(head->val);
            head=head->next;
        }
        return tobst(res, 0, res.size()-1);
    }
};


class Solution2 {
public:
    TreeNode* dfs(vector<ListNode*> &res, int l, int r){
        if(l>r)return nullptr;
        int mid=l+(r-l)/2;
        TreeNode * root=New TreeNode(res[mid]->val);
        root->left=dfs(res,l,mid-1);
        root->right=dfs(res,mid+1,r);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> res;
        while(head){
            res.push_back(head);
            head=head->next;
        }

        int n=res.size();
        return dfs(res,0,n-1);
    }
};