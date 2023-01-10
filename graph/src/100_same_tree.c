#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL){
        return 1;
    }else{
        if(p == NULL || q == NULL){
            return 0;
        }
        if(p->val == q->val){
            return isSameTree(p->left, q->left)&&isSameTree(p->right,q->right);
        }else{
            return 0;
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
    printf("two tree nodes are tree: %d\n",isSameTree(&a,&c));
    return 0;
}
