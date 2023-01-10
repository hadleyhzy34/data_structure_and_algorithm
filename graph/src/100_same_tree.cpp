#include <iostream>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL){
        return true;
    }else{
        if(p == NULL || q == NULL){
            return false;
        }
        if(p->val == q->val){
            return isSameTree(p->left, q->left)&&isSameTree(p->right,q->right);
        }else{
            return false;
        }
    }
}

int main()
{
    struct TreeNode a = {1};
    struct TreeNode b = {2};
    printf("two tree nodes are tree: %d\n",isSameTree(&a,&b));
    
    struct TreeNode c = {1};
    struct TreeNode d = {2};
    
    a.left = &d;
    c.left = &b;
    std::cout<<"two tree nodes are true? "<<isSameTree(&a,&c)<<std::endl;
    return 0;
}
