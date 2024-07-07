#include <iostream>
#include <vector>

struct MyList {
  int val;
  MyList *next;
  MyList() {
    val = 0;
    next = nullptr;
  }
  MyList(int v) {
    val = v;
    next = nullptr;
  };
};

class MyLinkedList {
public:
  MyLinkedList() { /* this->head = new MyList(0);  */
  }

  int get(int index) {
    MyList *node = head;
    int i = 0;
    while (i < index) {
      node = node->next;
      i++;
    }
    return node->val;
  }

  void addAtHead(int val) {
    MyList *tmp = new MyList(val);
    MyList *first = head->next;
    head->next = tmp;
    tmp->next = first;
  }

  void addAtTail(int val) {
    MyList *node = head;
    while (node->next) {
      node = node->next;
    }
    node->next = new MyList(val);
  }

  void addAtIndex(int index, int val) {
    MyList *node = head;
    int i = 0;
    while (i < index) {
      node = node->next;
      i++;
    }
    MyList *tmp = node->next;
    node->next = new MyList(val);
    node->next->next = tmp;
  }

  void deleteAtIndex(int index) {
    MyList *node = head;
    int i = 0;
    while (i < index - 1) {
      node = node->next;
      i++;
    }
    MyList *tmp = node->next->next;
    node->next = tmp;
  }

private:
  MyList *head = new MyList();
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
