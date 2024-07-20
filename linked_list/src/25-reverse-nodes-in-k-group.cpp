#include <iostream>
#include <string>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *first = head;
    int i = 0;
    while (i < k && head) {
      i++;
      head = head->next;
    }
    if (i == k) {
      ListNode *seg = reverse(first, k);
      ListNode *second = reverseKGroup(head, k);
      first->next = second;
      return seg;
    }
    return first;
  }

  ListNode *reverse(ListNode *node, int k) {
    int i = 0;
    ListNode *pre = nullptr;
    while (i < k) {
      i++;
      ListNode *nxt = node->next;
      node->next = pre;
      pre = node;
      node = nxt;
    }
    return pre;
  }
};
