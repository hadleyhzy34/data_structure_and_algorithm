#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

struct node {
  int val;
  std::set<std::string> ks;
  struct node *next;
  struct node *pre;
  node(int v) {
    val = v;
    next = nullptr;
    pre = nullptr;
  }
  node(int v, std::string s) {
    val = v;
    next = nullptr;
    pre = nullptr;
    ks.insert(s);
  }
};

class AllOne {
public:
  AllOne() {
    head = new node(0);
    tail = head;
  }

  void inc(std::string key) {
    if (s2n.count(key)) {
      int val = s2n[key]->val;
      if (s2n[key]->ks.size() == 1) {
        s2n[key]->val++;
      } else {
        s2n[key]->ks.erase(key);
        if (s2n[key]->next) {
          if (s2n[key]->next->val == val + 1) {
            s2n[key]->next->ks.insert(key);
            s2n[key] = s2n[key]->next;
          } else {
            node *tmp = new node(val + 1, key);
            s2n[key]->next->pre = tmp;
            tmp->next = s2n[key]->next;
            s2n[key]->next = tmp;
            tmp->pre = s2n[key];
            s2n[key] = tmp;
          }
        } else {
          s2n[key]->next = new node(val + 1, key);
          s2n[key]->next->pre = s2n[key];
          s2n[key] = s2n[key]->next;
          tail = s2n[key];
        }
      }
    } else {
      if (!head->next) {
        head->next = new node(1);
        head->next->pre = head;
        tail = head->next;
      } else {
        if (head->next->val == 1) {
          head->next->ks.insert(key);
          s2n[key] = head->next;
        } else {
          s2n[key] = new node(1, key);
          s2n[key]->pre = head;
          head->next->pre = s2n[key];
          head->next = s2n[key];
        }
      }
    }
  }

  void dec(std::string key) {
    int val = s2n[key]->val;
    if (s2n[key]->pre->val == val - 1) {
      s2n[key]->pre->ks.insert(key);
      s2n[key]->ks.erase(key);
      if (s2n[key]->ks.empty()) {
        s2n[key]->pre->next = s2n[key]->next;
        s2n[key] = s2n[key]->pre;
        if (!s2n[key]->next) {
          tail = s2n[key];
        }
      }
    } else {
      if (s2n[key]->ks.size() == 1) {
        s2n[key]->val--;
      } else {
        s2n[key]->ks.erase(key);
        node *tmp = new node(val - 1, key);
        s2n[key]->pre->next = tmp;
        tmp->pre = s2n[key]->pre;
        tmp->next = s2n[key];
        s2n[key]->pre = tmp;
        s2n[key]->ks.erase(key);
      }
    }
  }

  std::string getMaxKey() {
    if (head->next) {
      return *tail->ks.begin();
    } else {
      return "";
    }
  }

  std::string getMinKey() {
    if (head->next) {
      return *head->next->ks.begin();
    } else {
      return "";
    }
  }

private:
  std::unordered_map<std::string, node *> s2n;
  node *head;
  node *tail;
  // node *minNode;
  // node *maxNode;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
