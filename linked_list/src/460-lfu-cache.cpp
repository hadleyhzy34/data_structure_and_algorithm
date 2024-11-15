#include <iostream>
#include <list>
#include <map>
#include <unordered_map>

struct Node {
  int key;
  int val;
  int freq;
  int counter;
  std::list<Node *>::iterator iter;
  Node() {
    key = -1;
    freq = 0;
    counter = -1;
    val = -1;
  }
};
class LFUCache {
public:
  LFUCache(int capacity) {
    this->capacity = capacity;
    cnt = 0;
  }

  int get(int key) {
    if (umap.count(key)) {
      Node *node = umap[key];
      // remove this node from previous frequency
      m[node->freq].erase(node->iter);
      // update this node info
      node->counter = cnt++;
      node->freq++;
      m[node->freq].push_front(node);
      node->iter = m[node->freq].begin();
      return node->val;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (umap.count(key)) {
      auto node = umap[key];

      // remove it from current frequency
      m[node->freq].erase(node->iter);
      if (m[node->freq].empty()) {
        m.erase(node->freq);
      }
      node->counter = cnt++;
      node->val = value;
      node->freq++;
      m[node->freq].push_front(node);
      node->iter = m[node->freq].begin();
    } else {
      auto node = new Node();
      node->counter = cnt++;
      node->key = key;
      node->val = value;
      node->freq = 1;

      if (len == capacity) {
        int k = (*m.begin()).second.back()->key;
        (*m.begin()).second.pop_back();
        delete umap[k];
        umap.erase(k);
      }else{
        len++;
      }

      umap[key] = node;
      m[node->freq].push_front(node);
      node->iter = m[node->freq].begin();
    }
  }

private:
  std::unordered_map<int, Node *> umap;
  std::map<int, std::list<Node *>> m;
  int capacity;
  int len = 0;
  int cnt = 0;
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  // Initialize LFUCache with a capacity of 2
  LFUCache cache(2);

  // Test inserting and accessing cache elements
  cache.put(1, 1); // Cache stores {1=1}
  cache.put(2, 2); // Cache stores {1=1, 2=2}
  std::cout << cache.get(1)
            << "\n"; // Returns 1 and increases frequency of key 1
  cache.put(3, 3); // Removes key 2 (least frequently used) and stores {1=1,3=3}
  std::cout << cache.get(2) << "\n"; // Returns -1 (not found)
  std::cout << cache.get(3) << "\n"; // Returns 3
  cache.put(4, 4);                   // Removes key 1 and stores {3=3, 4=4}
  std::cout << cache.get(1) << "\n"; // Returns -1 (not found)
  std::cout << cache.get(3) << "\n"; // Returns 3
  std::cout << cache.get(4) << "\n"; // Returns 4

  return 0;
}
