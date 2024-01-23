#include <iostream>
#include <vector>
#include <queue>
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
    std::vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<int> res;
        int curSize = 0;

        if(root){
            q.push(root);
            curSize = 1;
        }else{
            return {};
        }
        
        int tmpSize;

        while(!q.empty()){
            tmpSize = 0;
            for(int i = 0; i < curSize; i++){
                if(q.front()->left){
                    q.push(q.front()->left);
                    tmpSize++; 
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                    tmpSize++;
                }
                if(i == curSize-1){
                    res.push_back(q.front()->val);
                }
                q.pop();
            }
            curSize = tmpSize;
        }
        return res;
    }
};
