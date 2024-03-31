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
  Node *construct(std::vector<std::vector<int>> &grid) {
    int n = grid.size();
    return quadTree(grid, 0, n - 1, 0, n - 1);
  }
  Node *quadTree(std::vector<std::vector<int>> &grid, int x1, int x2, int y1,
                 int y2) {
    if (x1 == x2 && y1 == y2) {
      Node *node = new Node(grid[x1][y1], true);
      return node;
    }
    Node *node = new Node(0, false);
    node->topLeft = quadTree(grid, x1, (x2 - x1) / 2, y1, (y2 - y1) / 2);
    node->topRight = quadTree(grid, (x2 - x1) / 2, x2, y1, (y2 - y1) / 2);
    node->bottomLeft = quadTree(grid, x1, (x2 - x1) / 2, (y2 - y1) / 2, y2);
    node->bottomRight = quadTree(grid, (x2 - x1) / 2, x2, (y2 - y1) / 2, y2);
    if (node->topLeft->isLeaf && node->topRight->isLeaf &&
        node->bottomLeft->isLeaf && node->bottomRight->isLeaf) {
      if (node->topLeft->val == node->topRight->val == node->bottomLeft->val ==
          node->bottomRight->val) {
        node->isLeaf = true;
        node->val = node->topLeft->val;
        node->topLeft = nullptr;
        node->topRight = nullptr;
        node->bottomLeft = nullptr;
        node->bottomRight = nullptr;
      }
    }
    return node;
  }
};
