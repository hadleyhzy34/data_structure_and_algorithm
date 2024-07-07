#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int characterReplacement(std::string s, int k) {
    std::unordered_map<char, int> umap;
    int ptr = 0;
    int res = 0;
    int len = 0;
    for (int i = 0; i < s.length(); i++) {
      if (i == 0) {
        umap[s[i]]++;
        len++;
      } else {
        if (s[i] == s[i - 1]) {
          umap[s[i]]++;
          len++;
          res = std::max(res, i - ptr + 1);
          continue;
        } else {
          umap[s[i]]++;
          bool check = false;
          for (auto &[key, val] : umap) {
            if (umap[key] + k >= (i - ptr + 1)) {
              check = true;
              break;
            }
          }
          if (check) {
            res = std::max(res, i - ptr + 1);
          } else {
            while (ptr < i) {
              umap[ptr]--;
              bool check = false;
              for (auto &[key, val] : umap) {
                if (umap[key] + k >= (i - ptr + 1)) {
                  check = true;
                  break;
                }
              }
              if (check) {
                break;
              }
            }
          }
        }
      }
    }
    return res;
  }
};
