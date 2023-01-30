from typing import Optional, TypeVar

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def isSameTree(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    if p == None and q == None:
        return True
    else:
        if p == None or q == None:
            return False
        else:
            return (p.val == q.val) and isSameTree(p.left,q.left) and isSameTree(p.right,q.right)

if __name__ == '__main__':
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(1)

    print(f'a is same as b: {isSameTree(a,b)}')
    
    a.left = b
    d.left = b
    print(f'a is same as d: {isSameTree(a,d)}')

    a.right = c
    d.right = b
    print(f'a is same as d: {isSameTree(a,d)}')
