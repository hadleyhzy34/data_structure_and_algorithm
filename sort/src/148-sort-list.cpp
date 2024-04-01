#include <iostream>
#include <string.h>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *sortList(ListNode *head) {
    ListNode *tmp = head;
    int len = 0;
    while (tmp) {
      len++;
      tmp = tmp->next;
    }
    return sort(head, tmp, len);
  }

  ListNode *divide(ListNode *node, int len) {
    ListNode *l = node;
    ListNode *r = node;
    int i = 0;
    while (i < len / 2) {
      r = node->next;
    }
    return r;
  }

  ListNode *merge(ListNode *l, ListNode *r, int len) {
    ListNode *tmp = new ListNode(0);
    ListNode *head = tmp;
    while (l || r) {
      if (!l || r->val < l->val) {
        tmp->next = r;
      }
      if (!r || l->val < r->val) {
        tmp->next = l;
      }
    }
    return head->next;
  }

  ListNode *sort(ListNode *l, ListNode *r, int len) {
    if (len == 1) {
      return merge(l, r, len);
    } else {
      ListNode *lr = divide(l, len / 2);
      ListNode *rr = divide(r, len / 2);
      l = sort(l, lr, len);
      r = sort(r, rr, len);
      return merge(l, r, len);
    }
  }
};
