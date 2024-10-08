#include <iostream>
#include <map>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> &words) {
    std::map<std::string, int> umap;
    for (auto word : words) {
      umap[word]++;
    }
    // printMap(umap);
    std::vector<int> res;

    int num = words.size();
    int c = words[0].length();
    std::vector<std::map<std::string, int>> utmps(c);
    for (auto i = 0; i + num * c - 1 < s.length(); i++) {
      int j = i % c;
      //   std::cout<<i<<" "<<j<<std::endl;
      if (utmps[j].empty()) {
        getUmap(utmps[j], s, i, num, c);
        // printMap(utmps[j]);
        if (utmps[j] == umap) {
          res.push_back(i);
        }
        // remove first c
        std::string first = s.substr(i, c);
        utmps[j][first]--;
        if (utmps[j][first] == 0) {
          utmps[j].erase(first);
        }
      } else {
        // add last c
        std::string last = s.substr(i + (num - 1) * c, c);
        utmps[j][last]++;
        if (utmps[j] == umap) {
          res.push_back(i);
        }
        // remove first c
        std::string first = s.substr(i, c);
        utmps[j][first]--;
        if (utmps[j][first] == 0) {
          utmps[j].erase(first);
        }
      }
    }
    return res;
  }

  void printMap(std::map<std::string, int> umap) {
    for (auto const x : umap) {
      std::cout << x.first << " " << x.second << std::endl;
    }
    std::cout << "finsieh" << std::endl;
    return;
  }

  void getUmap(std::map<std::string, int> &umap, std::string s, int idx,
               int num, int c) {
    for (auto i = idx; i < idx + num * c; i += c) {
      umap[s.substr(i, c)]++;
    }
    return;
  }
};

class Solution1 {
public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> &words) {
    std::map<std::string, int> umap;
    for (auto word : words) {
      umap[word]++;
    }
    // printMap(umap);
    std::vector<int> res;

    int num = words.size();
    int c = words[0].length();
    std::vector<std::map<std::string, int>> utmps(c, umap);
    for (auto i = 0; i + num * c - 1 < s.length(); i++) {
      int j = i % c;
      //   std::cout<<i<<" "<<j<<std::endl;
      if (i / c == 0) {
        getUmap(utmps[j], s, i, num, c);
        // printMap(utmps[j]);
        if (utmps[j].empty()) {
          res.push_back(i);
        }
        // add first c
        std::string first = s.substr(i, c);
        utmps[j][first]++;
        if (utmps[j][first] == 0) {
          utmps[j].erase(first);
        }
      } else {
        // add last c
        std::string last = s.substr(i + (num - 1) * c, c);
        utmps[j][last]--;
        if (utmps[j].empty()) {
          res.push_back(i);
        }
        // add first c
        std::string first = s.substr(i, c);
        utmps[j][first]++;
        if (utmps[j][first] == 0) {
          utmps[j].erase(first);
        }
      }
    }
    return res;
  }

  void printMap(std::map<std::string, int> umap) {
    for (auto const x : umap) {
      std::cout << x.first << " " << x.second << std::endl;
    }
    std::cout << "finsieh" << std::endl;
    return;
  }

  void getUmap(std::map<std::string, int> &umap, std::string s, int idx,
               int num, int c) {
    for (auto i = idx; i < idx + num * c; i += c) {
      std::string tmp = s.substr(i, c);
      umap[tmp]--;
      if (umap[tmp] == 0) {
        umap.erase(tmp);
      }
    }
    return;
  }
};
