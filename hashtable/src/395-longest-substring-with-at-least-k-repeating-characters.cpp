#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int longestSubstring(std::string s, int k) {
    int n = s.length();
    std::unordered_map<char, int> umap;
    int res = -1;
    for (int l = 1; l <= n; l++) {
      for (int i = 0; i + l - 1 < n; i++) {
        if (l < k) {
          if (i - l + 1 >= 0)
            umap[s[i - l + 1]]--;
          umap[s[i]]++;
        } else {
          umap[s[i - l + 1]]--;
          bool check = true;
          for (auto &[key, val] : umap) {
            if (umap[key] > 0 && umap[key] >= k) {
              continue;
            } else {
              check = false;
              break;
            }
          }
          if (check) {
            res = std::max(res, l);
          }
        }
      }
    }
    return res;
  }
};
