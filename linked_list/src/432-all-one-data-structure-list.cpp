#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

/*
list initialization
next/prev of list iterator
list emplace
list emplace_front
unordered_map<std::string, custom_data_type)
logic of inc and dec
*/

class AllOne {
public:
  AllOne() {}

  void inc(std::string key) {
    if (s2n.count(key)) {
      auto cur = s2n[key], nxt = std::next(cur);
      if (nxt == nodes.end() || nxt->second > cur->second + 1) {
        std::set<std::string> s({key});
        s2n[key] = nodes.emplace(nxt, std::make_pair(s, cur->second + 1));
      } else {
        nxt->first.insert(key);
        s2n[key] = nxt;
      }
      cur->first.erase(key);
      if (cur->first.empty()) {
        nodes.erase(cur);
      }
    } else {
      if (nodes.empty() || nodes.begin()->second > 1) {
        std::set<std::string> s({key});
        nodes.emplace_front(std::make_pair(s, 1));
      } else {
        nodes.begin()->first.insert(key);
      }
      s2n[key] = nodes.begin();
    }
  }

  void dec(std::string key) {
    auto cur = s2n[key];
    if (cur->second == 1) {
      s2n.erase(key);
    } else {
      auto pre = std::prev(cur);
      if (cur == nodes.begin() || pre->second < cur->second - 1) {
        std::set<std::string> s({key});
        s2n[key] = nodes.emplace(cur, std::make_pair(s, cur->second - 1));
      } else {
        pre->first.insert(key);
        s2n[key] = pre;
      }
      //   cur->first.erase(key);
      //   if (cur->first.empty()) {
      //     nodes.erase(cur);
      //   }
    }
    cur->first.erase(key);
    if (cur->first.empty()) {
      nodes.erase(cur);
    }
  }

  std::string getMaxKey() {
    if (nodes.empty()) {
      return "";
    } else {
      return *nodes.rbegin()->first.begin();
    }
  }

  std::string getMinKey() {
    if (nodes.empty()) {
      return "";
    } else {
      return *nodes.begin()->first.begin();
    }
  }

private:
  std::list<std::pair<std::set<std::string>, int>> nodes;
  std::unordered_map<std::string,
                     std::list<std::pair<std::set<std::string>, int>>::iterator>
      s2n;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
