#include <iostream>
#include <string.h>
#include <vector>

// Definition for a QuadTree node.
class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight,
       Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
public:
  Node *intersect(Node *quadTree1, Node *quadTree2) {
    if (quadTree1->isLeaf) {
      if (quadTree1->val) {
        return new Node(true, true);
      } else {
        return new Node(quadTree2->val, quadTree2->isLeaf, quadTree2->topLeft,
                        quadTree2->topRight, quadTree2->bottomLeft,
                        quadTree2->bottomRight);
      }
    } else if (quadTree2->isLeaf) {
      if (quadTree2->val) {
        return new Node(true, true);
      } else {
        return new Node(quadTree1->val, quadTree1->isLeaf, quadTree1->topLeft,
                        quadTree1->topRight, quadTree1->bottomLeft,
                        quadTree1->bottomRight);
      }
    }
    Node *o00 = intersect(quadTree1->topLeft, quadTree2->topLeft);
    Node *o01 = intersect(quadTree1->topRight, quadTree2->topRight);
    Node *o10 = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
    Node *o11 = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
    if (o00->isLeaf && o01->isLeaf && o10->isLeaf && o11->isLeaf &&
        o00->val == o01->val && o01->val == o10->val && o10->val == o11->val) {
      return new Node(o01->val, true);
    }
    return new Node(false, false, o00, o01, o10, o11);
  }
};
